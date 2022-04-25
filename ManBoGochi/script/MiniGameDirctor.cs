using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;
public class MiniGameDirctor : MonoBehaviour

{
    public SpriteRenderer renderer_run;

    public SpriteRenderer renderer_health;
    private float nextTime = 0.0f;
    // Start is called before the first frame update
    private float TimeLeft  =1.0f;
    private int iter = 0;
    // Start is called before the first frame update
    public int succ_or_fail;
    public int score = 0;

    public int heart = 4;

    public int max_score ;

    GameObject manbo_run;
    GameObject manbo_health;
    public Text Score_text;
    public Text heart_text;
    public Text speed_text;
    private int GameEndFlag;

    private int first_mini;
    public AudioSource BackGround;
    void Start()
    {
        this.manbo_run = GameObject.Find("Manbo_run");
        this.manbo_health = GameObject.Find("Manbo_health");
        renderer_run = manbo_run.GetComponent<SpriteRenderer>();
        renderer_health = manbo_health.GetComponent<SpriteRenderer>();
        succ_or_fail = PlayerPrefs.GetInt("succ_or_fail" , 1);
        score = PlayerPrefs.GetInt("score" , 0);
        heart = PlayerPrefs.GetInt("heart" , 4);
        max_score = PlayerPrefs.GetInt("max_score" ,0);
        first_mini = PlayerPrefs.GetInt("first_mini");
        //GameEndFlag = PlayerPrefs.GetInt("GameEndFlag" , 0);
        score++;
        if(score >=5)
        {
            BackGround.pitch += 0.2f *(score/5);
            TimeLeft -= 0.2f *(score/5);
        }
        if(succ_or_fail == 0)
        {
            //PlayerPrefs.SetInt("succ_or_fail" , 0);
            PlayerPrefs.SetInt("heart" , --heart);
            if(heart == 0)
            {
                //PlayerPrefs.SetInt("GamEndFlag" , 1);
                GameEndFlag = 1;
            }
        }
        if((score % 5) == 0 )
        {
            
            speed_text.text = "속도업!!!!";
        }
        PlayerPrefs.SetInt("score" , score);
        renderer_health.sprite = Resources.Load<Sprite>("Graphic/MiniGame/" +"ManBogoChi_mini_health_" + heart.ToString());
        Score_text.text = score + "m";
        //heart_text.text = "체력 :" +heart;
    }

    // Update is called once per frame
    void Update()
    {
        if(GameEndFlag == 0)
        {
        //
        if(succ_or_fail == 1 && iter<3)
        {
            renderer_run.sprite = Resources.Load<Sprite>("Graphic/MiniGame/" +"ManBogoChi_mini_main_succ_" + iter.ToString());
        }
        else if (succ_or_fail == 0 &&iter<3)
        {
            renderer_run.sprite = Resources.Load<Sprite>("Graphic/MiniGame/" +"ManBogoChi_mini_main_fail_" + iter.ToString());
        }
        if(iter >= 3)
        {
        renderer_run.sprite = Resources.Load<Sprite>("Graphic/MiniGame/" +"ManBogoChi_mini_main_" + iter.ToString());
        }
        if (iter == 5)
        {
            speed_text.text = "";
            //랜덤넘버로 4개의 씬을 로드 같은거 허용
            //라이프 playerprefs로 4개로 갖고 온 뒤 이전버튼으로 돌아가면 셋인트로 초기화 라이프에 따라서 다른 스프라이트 로딩
            //7개 프레임으로 구성 or 애니메이션 배경화면
            int rand = Random.Range(1,5);
            if(rand == 1)
            {
            SceneManager.LoadScene("MiniGameSub_01");
            }
            else if(rand == 2)
            {
            SceneManager.LoadScene("MiniGameSub_02");
            }
            else if(rand == 3)
            {
            SceneManager.LoadScene("MiniGameSub_03");
            }
            else if(rand == 4)
            {
            SceneManager.LoadScene("MiniGameSub_04");
            }
        }
        else if(Time.time>nextTime)
        {
            nextTime = Time.time + TimeLeft;
            iter++;
        }
        }
        else{
            //speed_text.text = "";
            heart_text.text = "수고하셨습니다.";
            if(score> max_score)
            {
                PlayerPrefs.SetInt("max_score" , score);
                max_score= score;
            }
            speed_text.text = "최고점수 : " + max_score;

        }
        if(Application.platform == RuntimePlatform.Android)
        {   
            
            if(Input.GetKey(KeyCode.Escape))
            {
                int step = PlayerPrefs.GetInt("WP", 0);
                step += (score *10);
                PlayerPrefs.SetInt("WP" , step);
                SceneManager.LoadScene("GameStartScene");
            }


        }
        

    }
}
