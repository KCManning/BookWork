﻿using UnityEngine;
using System.Collections;

public class NumberWizard : MonoBehaviour {
    int max;
    int min;
    int guess;

    // Use this for initialization
    void Start () {
        StartGame();
        
    }
	
	// Update is called once per frame
	void Update () {
        if(Input.GetKeyDown(KeyCode.UpArrow))
        {
            min = guess;
            NextGuess();
        } else if (Input.GetKeyDown(KeyCode.DownArrow))
        {
            max = guess;
            NextGuess();
        } else if (Input.GetKeyDown(KeyCode.Return))
        {
            print("I won!");
            StartGame();
       }

    }

    void StartGame()
    {
        max = 1000;
        min = 1;
        guess = 500;

        print("");
        print("========================");
        print("Welcome to Number Wizard");
        print("Pick a number in your head, but don't tell me");

        print("The highest number you can pick is " + max);
        print("The lowest number you can pick is " + min);

        print("Is you number higher or lower than " + guess + "?");
        print("Up for higher, Down for Lower, Return for equals");

        max++;

    }


    void NextGuess()
    {
        guess = (max + min) / 2;
        print("Is you number higher or lower than " + guess + "?");
        print("Up for higher, Down for Lower, Return for equals");
    }
}
