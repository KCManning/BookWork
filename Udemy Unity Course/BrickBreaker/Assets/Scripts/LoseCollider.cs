using UnityEngine;
using System.Collections;

public class LoseCollider : MonoBehaviour
{
    public Scene_Manager sm;

    void OnCollisionEnter2D (Collision2D collision)
    {
        Debug.Log("Collision");
    }

    void OnTriggerEnter2D (Collider2D collider)
    {
        Debug.Log("Trigger");
        sm.LoadScene("Lose");
    }
}
