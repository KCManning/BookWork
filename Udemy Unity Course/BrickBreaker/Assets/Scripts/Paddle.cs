using UnityEngine;
using System.Collections;

public class Paddle : MonoBehaviour {

    int gameUnits = 16;
    Vector3 paddlePOS;

    // Use this for initialization
    void Start () {
        paddlePOS = new Vector3(-1f, this.transform.position.y, 0f);
    }
	
	// Update is called once per frame
	void Update () {
        float mousePOSInBlocks = Input.mousePosition.x / Screen.width * gameUnits;

        paddlePOS.x = Mathf.Clamp(mousePOSInBlocks, 1f, 15f);

        //print(mousePOSInBlocks + ", " + paddlePOS);


        this.transform.position = paddlePOS;
	}
}
