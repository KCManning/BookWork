using UnityEngine;
using System.Collections;

public class LevelManager : MonoBehaviour
{

    public void LoadLevel(string name)
    {
        Debug.Log("LevelLoad() requested for " + name);
        print("LevelLoad() requested for " + name);
    }

    public void QuitRequest()
    {
        Debug.Log("Quit Requested");
        print("Quit Requested");
    }
}
