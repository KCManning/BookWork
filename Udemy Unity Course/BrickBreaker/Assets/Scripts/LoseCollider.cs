using UnityEngine;
using System.Collections;

public class LoseCollider : MonoBehaviour
{
   private Scene_Manager sm;

    void OnTriggerEnter2D (Collider2D collider)
    {
        sm = GameObject.FindObjectOfType<Scene_Manager>();
        sm.LoadScene("Lose");
    }
}
