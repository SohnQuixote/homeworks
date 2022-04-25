using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class ChangeScene : MonoBehaviour
{
    public void ToStore()
    {
        SceneManager.LoadScene("StoreScene");
    }
    public void ToInventory()
    {
        SceneManager.LoadScene("InventoryScene");
    }
    public void ToEndingWiki()
    {
        SceneManager.LoadScene("EndingWikipediaScene");
    }
}
