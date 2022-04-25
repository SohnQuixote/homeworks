using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Album : MonoBehaviour
{
    public Transform grid;

    private int imagecount;
    private Transform ImageList;
    private int locked;
    void Start()
    {
        for(int i = 0; i < 4; i++)
        {
            ImageList = grid.GetChild(i).GetChild(0).GetChild(0);
            imagecount = ImageList.childCount;

            for(int j = 0; j < imagecount; j++)
            {
                var image = ImageList.GetChild(j);
                var imagecomp = image.GetComponent<UnityEngine.UI.Image>();
                PlayerPrefs.SetInt("ManboGochi_egg_01", 1);
                locked = PlayerPrefs.GetInt(image.name, 0);

                if (locked == 1)
                    imagecomp.sprite = Resources.Load<Sprite>("Graphic/Character/" + image.name);

                else if(locked == 0)
                    imagecomp.sprite = Resources.Load<Sprite>("Graphic/locked");
            }
        }
    }
}
