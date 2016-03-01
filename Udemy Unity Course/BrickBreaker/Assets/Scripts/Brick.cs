using UnityEngine;
using System.Collections;

public class Brick : MonoBehaviour {

    //public int maxHits;
    public AudioClip crack;

    private int timesHit;
    private Scene_Manager sm;
    public Sprite[] hitSprites;
    private bool isBreakable;

    public GameObject smoke;

    public static int breakableCount;

	// Use this for initialization
	void Start () {
        isBreakable = (this.tag == "Breakable");
        if (isBreakable) { breakableCount++; }
        timesHit = 0;
        sm = GameObject.FindObjectOfType<Scene_Manager>();
    }
	
	// Update is called once per frame
	void Update () {


    }

    void LoadSprites()
    {
        int index = timesHit - 1;
        if(hitSprites[index])
            this.GetComponent<SpriteRenderer>().sprite = hitSprites[index];
    }

    void HandleHits()
    {
        timesHit++;
        AudioSource.PlayClipAtPoint(crack, transform.position);
        if (timesHit >= hitSprites.Length + 1)
        { 
            breakableCount--;
            Debug.Log("Remaining brick: " + breakableCount);
            sm.BrickDestroyed();
           GameObject smokePuff =  Instantiate(smoke, transform.position, Quaternion.identity) 
                as GameObject;
            smokePuff.GetComponent<ParticleSystem>().startColor = 
                gameObject.GetComponent<SpriteRenderer>().color;
            Destroy(gameObject);

        }
        else
        {
            LoadSprites();
        }

    }


    void OnCollisionEnter2D(Collision2D col)
    {
       
        if (isBreakable) { HandleHits(); }

    }

}
