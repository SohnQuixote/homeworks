using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Buy : MonoBehaviour
{
    public Transform SelectedItem;
    public Transform ItemRoot;          //유니티 인벤토리씬에 있는 ItemList 오브젝트를 가리킴
    public GameObject failwin;
    public GameObject successwin;
    public UnityEngine.UI.Text mymoney;

    private int temp;
    private int money;
    private int cost;
    public void OnClickBuy()
    {
        var selecteditem = SelectedItem.GetComponent<ItemIndex>();
        var item = ItemRoot.GetChild(selecteditem.index).GetComponent<Item>();       //ItemList 오브젝트에서 선택된 아이템을 반환
        money = PlayerPrefs.GetInt("WP", 0);
        cost = int.Parse(item.icost.text);

        if (cost <= money)
        {
            PlayerPrefs.SetInt("WP", money - cost);
            mymoney.text = PlayerPrefs.GetInt("WP", 0).ToString() + "WP";

            temp = PlayerPrefs.GetInt(item.name, 0);
            temp += 1;
            PlayerPrefs.SetInt(item.name, temp);
            successwin.SetActive(true);
        }
        else
        {
            failwin.SetActive(true);
        }
    }

    public void OnFailYes()
    {
        failwin.SetActive(false);
    }
    public void OnSuccYes()
    {
        successwin.SetActive(false);
    }
}
