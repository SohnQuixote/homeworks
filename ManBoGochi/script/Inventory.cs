using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Inventory : MonoBehaviour
{
    public ItemBuffer itemBuffer;
    public Transform ItemRoot;          //유니티 인벤토리씬에 있는 ItemList 오브젝트를 가리킴

    private List<Item> itemList;        //스크립트에서 사용할 item을 원소로 가지는 List

    // Start is called before the first frame update
    void Start()
    {
        itemList = new List<Item>();

        int itemCount = ItemRoot.childCount;        //ItemList 오브젝트 내부에 몇개의 하위 오브젝트가 있는지 반환. 즉, 인벤토리의 ItemList 오브젝트 내부에 있는 item 오브젝트의 수를 나타냄

        for (int i = 0; i < itemCount; i++)
        {
            var item = ItemRoot.GetChild(i).GetComponent<Item>();       //ItemList 오브젝트에서 i번째 item 오브젝트를 반환

            if (i < itemBuffer.items.Count)
            {
                item.SetItem(itemBuffer.items[i]);
                item.SetCount(itemBuffer.items[i]);
            }
            else
            {
                item.GetComponent<UnityEngine.UI.Button>().interactable = false;
            }

            itemList.Add(item);
        }
    }

    // Update is called once per frame
    void Update()
    {

    }
}
