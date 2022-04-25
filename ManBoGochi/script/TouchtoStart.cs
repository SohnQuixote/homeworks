using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class TouchtoStart : MonoBehaviour
{
    int a=0;
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        if(a == 0)
        {
            this.transform.localScale += new Vector3(0.1f,0.1f,0.1f);
            a=1;
        }
        else if(a == 1)
        {
            this.transform.localScale -= new Vector3(0.1f,0.1f,0.1f); 
            a=0;
        }
    }
}
