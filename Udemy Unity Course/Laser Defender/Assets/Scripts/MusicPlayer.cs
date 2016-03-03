using UnityEngine;
using System.Collections;

public class MusicPlayer : MonoBehaviour {
	static MusicPlayer instance = null;

    public AudioClip start;
    public AudioClip game;
    public AudioClip end;

    private AudioSource music;
	
	void Start () {
		if (instance != null && instance != this) {
			Destroy (gameObject);
			print ("Duplicate music player self-destructing!");
		} else {
			instance = this;
			GameObject.DontDestroyOnLoad(gameObject);
            music = GetComponent<AudioSource>();
		}
		
	}

    void OnLevelWasLoaded(int level)
    {
        Debug.Log("Play that funky music " + level + " boy!");
        music.Stop();

        switch (level)
        {
            case 0:
                music.clip = start;
                break;
            case 1:
                music.clip = game;
                break;
            case 2:
                music.clip = end;
                break;
            default: break;
        }

        music.loop = true;
        music.Play();
    }

}
