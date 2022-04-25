using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;
public class MinGame01Script : MonoBehaviour
{
    public SpriteRenderer renderer_bomb;
    GameObject manbo_bomb;
    public GameObject ManBoGochi_mini_01_insect;

    public GameObject Manbo_insect_killed;

    public AudioSource success;
    public AudioSource fail;

    public AudioSource slap;
    private string name;
    private float nextTime = 0.0f;
    // Start is called before the first frame update
    private float TimeLeft  =1.0f;
    private int iter = 6;

    private int length;

    private int catched = 0;


    //private var insect_prefab;
    private List<Vector2> poslist = new List<Vector2>();
    private List<Object> objlist = new List<Object>();
    public Text GuideText;

    private int count= 1;
    void CreatePositions()
    {

        int flag =0;

        float randomX = Random.Range(-1.8f,1.8f);
        float randomY = Random.Range(-3.0f,3.5f);
        Vector2 randomPos = new Vector2(randomX,randomY);
        poslist.Add(randomPos);
        Object obj;
        obj =Instantiate(ManBoGochi_mini_01_insect , randomPos, Quaternion.identity);
        objlist.Add(obj);
    }
    /*public static BlackBox CreateNewBlackBox()
    {
        float randomX = Random.Range(-1.0f,1.0f);
        float randomY = Random.Range(-3.0f,3.0f);
        var insect_Prefab = Resources.Load<BlackBox>("ManBoGochi_mini_01_insect");
        return Instantiate(insect_Prefab  , new Vector3(randomX, randomY, 0f));
    }*/



    void Start()
    {
        
        length = Random.Range(5,10);
        for (int i=0;i<length;i++)
        {
            
            CreatePositions();        
            count++;
        }
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
            if(catched >= length)
                {/*mg.set_succ_or_fail(true);*/PlayerPrefs.SetInt("succ_or_fail" , 1); GuideText.text = "성공!!!";success.Play();}
            else 
                {/*mg.set_succ_or_fail(false);*/PlayerPrefs.SetInt("succ_or_fail" , 0); GuideText.text = "실패...";fail.Play();}            
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
                //Debug.Log("Touched");
                Vector3 wp = Camera.main.ScreenToWorldPoint(Input.mousePosition);
                Vector2 touchPos = new Vector2(wp.x,wp.y);
                int flag = 0;
                int index = 0;
                for (int i=0;i<length;i++)
                {
                    if(Vector2.Distance(touchPos,poslist[i]) < 0.45f)
                    {
                        flag= 1;
                        index = i;
                        slap.Play();
                        break;
                    }
                }
                if(flag == 1)
                {
                    Destroy(objlist[index]);
                    Instantiate(Manbo_insect_killed , poslist[index], Quaternion.identity);
                    catched++;
                }
            }
            if(Input.GetKey(KeyCode.Escape))
            {
                SceneManager.LoadScene("GameStartScene");
            }


        }
    }
}
