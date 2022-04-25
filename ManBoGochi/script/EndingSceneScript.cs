using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;
public class EndingSceneScript : MonoBehaviour
{
    public GameObject manbo_ending;
    public SpriteRenderer ending_renderer;

    public Text ending_text;
    private string species;

    private int species_int;

    //private int random_ending;
    private int ending;
    private float hunger;
    private float feeling;
    private float maxhunger;
    private float maxfeeling;
    // Start is called before the first frame update
    void Start()
    {
        ending_renderer = manbo_ending.GetComponent<SpriteRenderer>();
        species = PlayerPrefs.GetString("species");
        species_int = int.Parse(species);

        hunger = PlayerPrefs.GetFloat("hunger", 0);
        feeling = PlayerPrefs.GetFloat("feeling", 0);
        maxhunger = PlayerPrefs.GetFloat("maxhunger", 0);
        maxfeeling = PlayerPrefs.GetFloat("maxfeeling", 0);

        if ((maxhunger / 2 <= hunger) && (maxfeeling / 2 > feeling))
            ending = 1;
        else if ((maxhunger / 2 > hunger) && (maxfeeling / 2 <= feeling))
            ending = 2;
        else
            ending = 3;

        //random_ending = Random.Range(1,4);
        if (species_int == 3)
        {
            ending_renderer.sprite = Resources.Load<Sprite>("Graphic/Character/manbo_ending_3");
            PlayerPrefs.SetInt("manbo_ending_3", 1);
        }
        else
        {
            ending_renderer.sprite = Resources.Load<Sprite>("Graphic/Character/manbo_ending_" + species +"_"+ ending.ToString());
            PlayerPrefs.SetInt("manbo_ending_" + species + "_" + ending.ToString(), 1);
        }
        switch(species_int)
        {
            case 1:
            if(ending == 1)
            {
                ending_text.text = "학교 졸업!";
            }
            else if(ending == 2)
            {
                ending_text.text = "축구 선수";
            }
            else{
                ending_text.text = "바둑 기사";
            }
            break;
            case 2:
            if(ending ==1)
            {
                ending_text.text = "단결!";
            }
            else if(ending == 2)
            {
                ending_text.text = "경 찰";
            }
            else{
                ending_text.text = "농구 선수";
            }

            break;
            case 3:
            ending_text.text = "잘 가렴..";

            break;
            default:

            break;

        }
    }

    // Update is called once per framez
    void Update()
    {
        if(Application.platform == RuntimePlatform.Android)
        {   
            
            if(Input.GetKey(KeyCode.Escape))
            {

                SceneManager.LoadScene("GameStartScene");
            }


        }
        
    }
}
