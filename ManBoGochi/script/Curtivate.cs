using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;
public class Curtivate : MonoBehaviour
{
    public GameObject manbo_egg;
    public GameObject manbo_background;
    public SpriteRenderer renderer;
    public Animator anim;
    public SpriteRenderer back_renderer;
    public Sprite image1;
    public Sprite image2;
    public Sprite image3;
    public Transform status;

    private int species;
    private string shape;
    private float exp;
    private Slider hunger_slider;
    private Slider feeling_slider;
    private Slider exp_slider;
    private int[] spec1 = new int[2] { 1, 3 };
    private int[] spec2 = new int[2] { 2, 3 };

    public void OnClickEvol()
    {
        exp = PlayerPrefs.GetFloat("exp", 0);
        hunger_slider = status.GetChild(0).GetComponent<Slider>();
        feeling_slider = status.GetChild(1).GetComponent<Slider>();
        exp_slider = status.GetChild(2).GetComponent<Slider>();
        if (exp >= exp_slider.maxValue)
        {
            renderer = manbo_egg.GetComponent<SpriteRenderer>();
            back_renderer = manbo_background.GetComponent<SpriteRenderer>();
            shape = PlayerPrefs.GetString("shape", "ManboGochi_egg_01");
            if(shape.Contains("egg"))
            {
                if(shape.Contains("01"))
                {
                    species = Random.Range(0, 2);
                    species = spec1[species];
                }
                else if(shape.Contains("02"))
                {
                    species = Random.Range(0, 2);
                    species = spec2[species];
                }

                anim.enabled = false;
                PlayerPrefs.SetString("species", species.ToString());
                shape = "manboGochi_creature_kid_0" + species.ToString();
                renderer.sprite = Resources.Load<Sprite>("Graphic/Character/" + shape);
                back_renderer.sprite = Resources.Load<Sprite>("Graphic/BackGround/MANBO_BACKGROUND_03");
                
                PlayerPrefs.SetString("shape", shape);
                PlayerPrefs.SetInt(shape, 1);

                hunger_slider.maxValue = 2000;
                feeling_slider.maxValue = 2000;
                exp_slider.maxValue = 2000;
            }
            else if(shape.Contains("kid"))
            {
                anim.enabled= false;
                shape = "ManBoGochi_creature_mid_0" + PlayerPrefs.GetString("species", "-1");
                renderer.sprite = Resources.Load<Sprite>("Graphic/Character/" + shape);
                back_renderer.sprite = Resources.Load<Sprite>("Graphic/BackGround/MANBO_BACKGROUND_04");
                
                PlayerPrefs.SetString("shape", shape);
                PlayerPrefs.SetInt(shape, 1);

                hunger_slider.maxValue = 4000;
                feeling_slider.maxValue = 4000;
                exp_slider.maxValue = 4000;
            }
            else if (shape.Contains("mid"))
            {
                species = Random.Range(1, 3);
                shape = "ManboGochi_egg_0" + species;
                renderer.sprite = Resources.Load<Sprite>("Graphic/Character/" + shape);
                
                PlayerPrefs.SetString("shape", shape);
                PlayerPrefs.SetInt(shape, 1);

                hunger_slider.maxValue = 1000;
                feeling_slider.maxValue = 1000;
                exp_slider.maxValue = 1000;
                SceneManager.LoadScene("EndingScene");
            }
            PlayerPrefs.SetFloat("hunger", 0);
            PlayerPrefs.SetFloat("feeling", 0);
            PlayerPrefs.SetFloat("exp", 0);
            PlayerPrefs.SetFloat("maxhunger", hunger_slider.maxValue);
            PlayerPrefs.SetFloat("maxfeeling", feeling_slider.maxValue);
            PlayerPrefs.SetFloat("maxexp", exp_slider.maxValue);

            hunger_slider.value = PlayerPrefs.GetFloat("hunger", 0);
            feeling_slider.value = PlayerPrefs.GetFloat("feeling", 0);
            exp_slider.value = PlayerPrefs.GetFloat("exp", 0);
        }
    }
}
