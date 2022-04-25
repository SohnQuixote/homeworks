using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PopupStatus : MonoBehaviour
{
    public GameObject panel;

    public void OnClick()
    {
        if (panel.active == true)
            panel.SetActive(false);
        else if (panel.active == false)
            panel.SetActive(true);
    }
}
