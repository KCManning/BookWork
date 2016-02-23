using UnityEngine;
using System.Collections;

public class Ball : MonoBehaviour {
    public Paddle paddle;

    private Vector3 paddleToBallVector;
    private bool startGame;

	// Use this for initialization
	void Start () {

        paddleToBallVector = this.transform.position - paddle.transform.position;
        startGame = false;

        //print(paddleToBallVector);
	}
	
	// Update is called once per frame
	void Update () {

        if (!startGame)
        {
            //lock ball to paddle
            this.transform.position = paddle.transform.position + paddleToBallVector;

            //launches pall and starts game on mouse press
            if (Input.GetMouseButtonDown(0))
            {
                this.GetComponent<Rigidbody2D>().velocity = new Vector2(2f, 10f);
                startGame = true;
            }//end if mouse
        }//end if startGame
    }//end update
}//end Ball class
