using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Item : MonoBehaviour
{
    public ItemProperty iprop;
    public Transform SelectedItem;
    public UnityEngine.UI.Image image;
    public UnityEngine.UI.Image sitem;
    public UnityEngine.UI.Text iexplain;
    public UnityEngine.UI.Text icost;
    public UnityEngine.UI.Image countimage;
    public UnityEngine.UI.Text icount;
    public UnityEngine.UI.Button Buy;

    private string curexplain;
    private int curcost;
    private int curindex;
    private int curcount;


    public void SetItem(ItemProperty iprop)
    {
        this.iprop = iprop;

        if (iprop == null)
        {
            image.enabled = false;

            gameObject.name = "Empty";
        }
        else
        {
            image.enabled = true;

            gameObject.name = iprop.name;
            image.sprite = iprop.sprite;
            curexplain = iprop.explain;
            curcost = iprop.cost;
            curindex = iprop.index;
        }
    }

    public void SetCount(ItemProperty iprop)
    {
        if(iprop == null)
        {
            image.enabled = false;

            gameObject.name = "Empty";
        }
        else
        {
            icount.enabled = true;
            countimage.enabled = true;

            curcount = PlayerPrefs.GetInt(iprop.name, 0);
            icount.text = curcount.ToString();
        }
    }

    public void OnClickItem()
    {
        var selecteditem = SelectedItem.GetComponent<ItemIndex>();
        selecteditem.index = curindex;

        sitem.enabled = true;
        sitem.sprite = image.sprite;

        iexplain.text = gameObject.name + ", " + curexplain;
        icost.text = curcost.ToString();

        Buy.interactable = true;
    }
}
