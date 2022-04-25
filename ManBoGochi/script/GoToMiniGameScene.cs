using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;
public class GoToMiniGameScene : MonoBehaviour
{
    public void GoMini()
    {
        SceneManager.LoadScene("MiniGameScene");
    }
    
}
