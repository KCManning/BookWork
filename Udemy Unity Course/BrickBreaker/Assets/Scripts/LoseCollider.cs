using UnityEngine;
using System.Collections;

public class LoseCollider : MonoBehaviour
{
   private Scene_Manager sm;

    void OnTriggerEnter2D (Collider2D collider)
    {
        if (GameObject.FindObjectOfType<Brick>())
            Brick.breakableCount = 0;

        sm = GameObject.FindObjectOfType<Scene_Manager>();

        sm.LoadScene("Lose");
    }
}
