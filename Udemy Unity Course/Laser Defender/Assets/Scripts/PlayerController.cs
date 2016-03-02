using UnityEngine;
using System.Collections;

public class PlayerController : MonoBehaviour {
    public GameObject beamPrefab;
    public float speed = 15.0f;
    public float padding = 1.0f;
    public float projectileSpeed = 2f;
    public float firingRate = 2f;

    float xmin;
    float xmax;

	// Use this for initialization
	void Start () {

        float distance = transform.position.z - Camera.main.transform.position.z;

        Vector3 leftmost = Camera.main.ViewportToWorldPoint(new Vector3(0, 0, distance));
        Vector3 rightmost = Camera.main.ViewportToWorldPoint(new Vector3(1, 1, distance));

        xmin = leftmost.x + padding;
        xmax = rightmost.x - padding;

    }

    // Update is called once per frame
    void Update() {
        if (Input.GetKey(KeyCode.A) || Input.GetKey(KeyCode.LeftArrow))
        {
            transform.position += Vector3.left * speed * Time.deltaTime;
        }
        else if (Input.GetKey(KeyCode.D) || Input.GetKey(KeyCode.RightArrow))
        {
            transform.position += Vector3.right * speed * Time.deltaTime;
        }
        
        float newX = Mathf.Clamp(transform.position.x, xmin, xmax);
        transform.position = new Vector3(newX, transform.position.y, 0f);

        if (Input.GetKeyDown(KeyCode.Space) || Input.GetKeyDown(KeyCode.UpArrow) 
            || Input.GetKeyDown(KeyCode.W))
        {
            InvokeRepeating("Fire", 0.000001f, firingRate);
        }
        if (Input.GetKeyUp(KeyCode.Space) || Input.GetKeyUp(KeyCode.UpArrow)
            || Input.GetKeyUp(KeyCode.W))
        {
            CancelInvoke("Fire");
        }
    }

    void Fire()
    {
        GameObject beam = Instantiate(beamPrefab, transform.position,
                  Quaternion.identity) as GameObject;
        beam.GetComponent<Rigidbody2D>().velocity = new Vector3(0, projectileSpeed, 0);
    }
}
