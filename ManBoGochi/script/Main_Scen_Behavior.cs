using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.InputSystem;
using UnityEngine.InputSystem.Controls;
public class Main_Scen_Behavior : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        if(Input.GetMouseButton(0))
        {
            SceneManager.LoadScene("GameStartScene");
        }
        if(Application.platform == RuntimePlatform.Android)
            if(Input.GetKey(KeyCode.Escape))
               Application.Quit();
    }
}
