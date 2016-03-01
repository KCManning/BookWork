using UnityEngine;
using System.Collections;

public class Paddle : MonoBehaviour {

    int gameUnits = 16;
    Vector3 paddlePOS;
    public bool autoPlay = false;

    private Ball ball;

    // Use this for initialization
    void Start () {
        paddlePOS = new Vector3(-1f, this.transform.position.y, 0f);
        ball = GameObject.FindObjectOfType<Ball>();
    }
	
	// Update is called once per frame
	void Update () {
        if (autoPlay)
        {
            AutoPlay();
        }
        else
        {
            MoveWithMouse();
        }

        this.transform.position = paddlePOS;
    }

    void MoveWithMouse()
    {
        float mousePOSInBlocks = Input.mousePosition.x / Screen.width * gameUnits;

        paddlePOS.x = Mathf.Clamp(mousePOSInBlocks, 1f, 15f);      
    }

    void AutoPlay()
    {
        paddlePOS.x = ball.transform.position.x;
    }
}
