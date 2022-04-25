using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Inventory : MonoBehaviour
{
    public ItemBuffer itemBuffer;
    public Transform ItemRoot;          //����Ƽ �κ��丮���� �ִ� ItemList ������Ʈ�� ����Ŵ

    private List<Item> itemList;        //��ũ��Ʈ���� ����� item�� ���ҷ� ������ List

    // Start is called before the first frame update
    void Start()
    {
        itemList = new List<Item>();

        int itemCount = ItemRoot.childCount;        //ItemList ������Ʈ ���ο� ��� ���� ������Ʈ�� �ִ��� ��ȯ. ��, �κ��丮�� ItemList ������Ʈ ���ο� �ִ� item ������Ʈ�� ���� ��Ÿ��

        for (int i = 0; i < itemCount; i++)
        {
            var item = ItemRoot.GetChild(i).GetComponent<Item>();       //ItemList ������Ʈ���� i��° item ������Ʈ�� ��ȯ

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
