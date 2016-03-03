using UnityEngine;
using System.Collections;

public class EnemySpawner : MonoBehaviour {
    public GameObject enemyPrefab;
    public float width = 10f;
    public float height = 5f;

    public float speed = 2.0f;
    public float padding = 5.0f;

    float xmin;
    float xmax;

    private bool movingRight = true;


    // Use this for initialization
    void Start () {
        float distance = transform.position.z - Camera.main.transform.position.z;

        Vector3 leftmost = Camera.main.ViewportToWorldPoint(new Vector3(0, 0, distance));
        Vector3 rightmost = Camera.main.ViewportToWorldPoint(new Vector3(1, 0, distance));

        xmin = leftmost.x + padding;
        xmax = rightmost.x - padding;

        Spawn();

       

        }	

    bool AllMembersDead()
    {
        foreach(Transform childPositionGameObject in transform)
        {
            if (childPositionGameObject.childCount > 0)
                return false;
        }

        return true;
    }

    void Spawn()
    {
        foreach (Transform child in transform)
        {
            GameObject enemy = Instantiate(enemyPrefab, child.transform.position,
                Quaternion.identity) as GameObject;
            enemy.transform.parent = child;
        }

    }

    public void OnDrawGizmos()
    {
        Gizmos.DrawWireCube(transform.position, new Vector3(width, height, 0));
    }

    // Update is called once per frame
    void Update () {
        if(movingRight)
        {
            transform.position += Vector3.right * speed * Time.deltaTime;
        }
        else
        {
            transform.position += Vector3.left * speed * Time.deltaTime;
        }

        float rightEdgeOfFormation = transform.position.x + (0.5f * width);
        float leftEdgeOfFormation = transform.position.x - (0.5f * width);

        if(rightEdgeOfFormation > xmax) { movingRight = false; }
        else if ( leftEdgeOfFormation < xmin) { movingRight = true; }

        if (AllMembersDead())
        {
            Spawn();
        }

        //float newX = Mathf.Clamp(transform.position.x, xmin, xmax);
        // transform.position = new Vector3(newX, transform.position.y, 0f);
    }
}
