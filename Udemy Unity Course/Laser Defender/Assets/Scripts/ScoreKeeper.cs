using UnityEngine;
using System.Collections;
using UnityEngine.UI;

public class ScoreKeeper : MonoBehaviour {

    public static int score = 0;
    private Text myText;

    void Start()
    {
        myText = GetComponent<Text>();
        myText.text = score.ToString();
    }
    public void Score(int points)
    {
        score += points;
        myText.text = score.ToString();
    }
    public static void Reset()
    {
        score = 0;
    }
}
