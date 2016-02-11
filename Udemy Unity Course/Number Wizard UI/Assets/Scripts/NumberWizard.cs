using UnityEngine;
using UnityEngine.UI;
using System.Collections;
using UnityEngine.SceneManagement;

public class NumberWizard : MonoBehaviour
{
    int max;
    int min;
    int guess;
    const int MAX_GUESSES = 10;
    int guesses;

    public Text txtGuess;

    // Use this for initialization
    void Start() { StartGame(); }

    // Update is called once per frame
    void Update()
    {
        if (Input.GetKeyDown(KeyCode.UpArrow)) { GuessHigher(); }
        else if (Input.GetKeyDown(KeyCode.DownArrow)) { GuessLower(); }
    }

    public void GuessHigher()
    {
        min = guess;
        NextGuess();
    }

    public void GuessLower()
    {
        max = guess;
        NextGuess();
    }

    void StartGame()
    {
        max = 1000;
        min = 1;
        max++;
        guess = Random.Range(min, max);
        txtGuess.text = guess.ToString();
    }

    void NextGuess()
    {
        guesses++;
        if (guesses >= MAX_GUESSES)
            SceneManager.LoadScene("Lose");
        guess = Random.Range(min, max);
        txtGuess.text = guess.ToString();
    }
}
