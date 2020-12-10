using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class enemyShooter : MonoBehaviour
{
     public bool toggle;
     public AudioSource launch;
     public GameObject projectile;

    // Start is called before the first frame update
    void Start()
    {
        //Start the coroutine we define below named ExampleCoroutine.
        toggle = true;

    }

    void Update()
    {

         if (toggle == true)
         {
              StartCoroutine(ExampleCoroutine());
         }
    }

    IEnumerator ExampleCoroutine()
    {
         toggle = false;
         //waits for random time before launching cannon ball
         yield return new WaitForSeconds(Random.Range(0, 12));
         Debug.Log("BOOM @ "+ Time.time);
         //cannon sound
         launch.Play();
         //creates and positions cannon ball
         GameObject cannonball = Instantiate (projectile);
         cannonball.transform.position = transform.position + transform.forward*8;
         //Launches cannon ball
         Rigidbody rb = cannonball.GetComponent<Rigidbody>();
         rb.velocity = transform.forward*21;
         toggle = true;
    }
}
