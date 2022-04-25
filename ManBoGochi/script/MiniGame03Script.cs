using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;
public class MiniGame03Script : MonoBehaviour
{
    public SpriteRenderer renderer_bomb;
    public Transform rotation_target;
    GameObject manbo_bomb;
    private string name;

    public Text GuideText;
    private float nextTime = 0.0f;
    // Start is called before the first frame update
    private float TimeLeft  =1.0f;
    private int iter = 6;

    private float speed =0;
    private bool stop_rotate = false;
    private int temp = 0;
    private int stop_number = 0;

    public AudioSource succ;
    public AudioSource fail;

    void Start()
    {
        speed = Random.Range(-10.0f,-15.0f);
        stop_number = Random.Range(1,4);
        GuideText.text = stop_number+ "번에서 멈춰!!";
        init_rotate();
        name = "ManBogoChi_mini_bomb_5";
        this.manbo_bomb = GameObject.Find("Manbo_bomb");
        renderer_bomb = manbo_bomb.GetComponent<SpriteRenderer>();
        renderer_bomb.sprite = Resources.Load<Sprite>("Graphic/MiniGame/" + name);
        int score = PlayerPrefs.GetInt("score");
        if(score >=5)
        {
            TimeLeft -= 0.1f *(score/5);
        }
        //Debug.Log("Hi");
    }
    public int Get_Euler()
    {
        return (int)rotation_target.eulerAngles.z;
    }
    private void init_rotate()
    {
        rotation_target.eulerAngles = Vector3.zero;
        stop_rotate = false;
    }
    private void update_rotate()
    {
        if(stop_rotate == false)
            rotation_target.Rotate(Vector3.forward * speed);

    }
    // Update is called once per frame
    void set_bomb_sprite(int a){
        name = "ManBogoChi_mini_bomb_" + a.ToString();
        renderer_bomb.sprite = Resources.Load<Sprite>("Graphic/MiniGame/" + name);
    }
    void Update()
    {
        update_rotate();
        if (iter == 0)
        {
            //Debug.Log(""+temp+" " + stop_number);
            if(stop_rotate == true)
            {
            if(stop_number == 1 &&temp>=270 && temp<=360 )
            {
                GuideText.text = "성공!!!";PlayerPrefs.SetInt("succ_or_fail" , 1); succ.Play();
            }
            else if (stop_number == 2 &&temp>=0 && temp<=90)
            {
                GuideText.text = "성공!!!";PlayerPrefs.SetInt("succ_or_fail" , 1); succ.Play();
            }
            else if (stop_number == 3 &&temp>=181 && temp<=269)
            {
                GuideText.text = "성공!!!";PlayerPrefs.SetInt("succ_or_fail" , 1); succ.Play();
            }
            else if (stop_number == 4 &&temp>=91 && temp<=180)
            {
                GuideText.text = "성공!!!";PlayerPrefs.SetInt("succ_or_fail" , 1); succ.Play();
            }
            else{GuideText.text = "실패...";PlayerPrefs.SetInt("succ_or_fail" , 0); fail.Play();}
            
            }
            else
                {GuideText.text = "실패...";PlayerPrefs.SetInt("succ_or_fail" , 0); fail.Play();}
            SceneManager.LoadScene("MiniGameScene");
        }
        else if(Time.time>nextTime && iter >0)
        {
            nextTime = Time.time + TimeLeft;
            set_bomb_sprite(--iter);
        }

        if(Application.platform == RuntimePlatform.Android)
        {
            if(Input.GetMouseButtonDown(0))
            {
                speed += 0.8f;
                if(speed >= 0)
                    {stop_rotate = true; temp = Get_Euler();}
            }

            if(Input.GetKey(KeyCode.Escape))
            {
                SceneManager.LoadScene("GameStartScene");
            }


        }
    }
}
