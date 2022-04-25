using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;
public class MiniGame04Script : MonoBehaviour
{
    public SpriteRenderer renderer_bomb;

    public SpriteRenderer renderer_calender;
    GameObject manbo_bomb;

    GameObject manbo_calender;
    private string name;
    private float nextTime = 0.0f;
    // Start is called before the first frame update
    private float TimeLeft  =1.0f;
    private int iter = 6;

    public Text GuideText;
    public Text DateText;

    private int curdate;
    private int wrongdate;

    private bool firsttouch = false;

    private bool lasttouch = false;

    Vector2 touchPos;
    Vector2 nextPos;
    public AudioSource succ;
    public AudioSource fail;
    public AudioSource tear;
    private float touchY;
    private float nextY;
    void Start()
    {
        curdate = Random.Range(15,32);
        wrongdate = Random.Range(curdate-10, curdate +1);
        GuideText.text = "오늘은 " + curdate + "일!";
        DateText.text = wrongdate.ToString();
        name = "ManBogoChi_mini_bomb_5";
        this.manbo_bomb = GameObject.Find("Manbo_bomb");
        this.manbo_calender = GameObject.Find("Manbo_calender");
        renderer_calender = manbo_calender.GetComponent<SpriteRenderer>();
        renderer_bomb = manbo_bomb.GetComponent<SpriteRenderer>();
        renderer_bomb.sprite = Resources.Load<Sprite>("Graphic/MiniGame/" + name);
        int score = PlayerPrefs.GetInt("score");
        if(score >=5)
        {
            TimeLeft -= 0.2f *(score/5);
        }
        //Debug.Log("Hi");
    }

    // Update is called once per frame
    void set_bomb_sprite(int a){
        name = "ManBogoChi_mini_bomb_" + a.ToString();
        renderer_bomb.sprite = Resources.Load<Sprite>("Graphic/MiniGame/" + name);
    }
    void Update()
    {
        if (iter == 0)
        {
            SceneManager.LoadScene("MiniGameScene");
            if(wrongdate== curdate)
                {GuideText.text= "성공!!!";PlayerPrefs.SetInt("succ_or_fail" , 1);succ.Play();}
            else 
                {GuideText.text ="실패...";PlayerPrefs.SetInt("succ_or_fail" , 0);fail.Play();}
        }
        else if(Time.time>nextTime && iter >0)
        {
            nextTime = Time.time + TimeLeft;
            set_bomb_sprite(--iter);
        }
        

        if(Application.platform == RuntimePlatform.Android)
        {

            if(Input.GetKey(KeyCode.Escape))
            {
                SceneManager.LoadScene("GameStartScene");
            }
            if(Input.GetMouseButtonDown(0) && firsttouch == false)
            {
                Vector3 wp = Camera.main.ScreenToWorldPoint(Input.mousePosition);
                touchPos = new Vector2(wp.x,wp.y);
                touchY = touchPos.y;
                firsttouch = true;
                lasttouch = false;
                Debug.Log(touchPos.x.ToString());
            }
            if (Input.GetMouseButtonUp(0))
            {
                Vector3 wp = Camera.main.ScreenToWorldPoint(Input.mousePosition);
                lasttouch = true;
                nextPos = new Vector2(wp.x,wp.y);
                nextY = nextPos.y;
                firsttouch = false;
                tear.Play();
                
            }
        if(touchY>nextY && lasttouch == true)
        {
            wrongdate++;
            lasttouch = false;
            DateText.text = wrongdate.ToString();
            renderer_calender.sprite = Resources.Load<Sprite>("Graphic/MiniGame/" +"ManBogoChi_mini_04_2");
        }

        }
    }
}
