using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class crash : MonoBehaviour
{
     public int hits;
     private int sink;
     
     public AudioSource splash;
     public AudioSource killed;
     public Collider selfCollider;

     public AudioSource health7;
     public AudioSource health6;
     public AudioSource health5;
     public AudioSource health4;
     public AudioSource health3;
     public AudioSource health2;
     public AudioSource health1;

     void Start()
    {
         hits = 0;

    }

    void OnCollisionEnter(Collision coll)
    {
         if (coll.gameObject.tag == "Projectile") //cannonballs are the projectiles
         {
              if (gameObject.tag == "Enemy")//when cannonballs hit
             {
                  //destroy cannonballs on impact
                  Destroy(coll.gameObject);
                  //play impact sound
                  splash.Play();

                  if (hits == 2) //3 hits sink the enemy boat
                  {
                       //play killed sound
                       killed.Play();
                       //turn off enemy collider
                       var m_Collider = selfCollider.GetComponent<Collider>();
                       m_Collider.enabled = false;
                       //reset hit count
                       hits = 0;
                       //add to casualty count in gameEngine script
                       GameObject.Find("GameEngine").GetComponent<gameEngine>().casualty++;
                  }

                  else
                  {
                       //keep track of hits to enemy boat
                       hits++;
                       Debug.Log("Hit");
                  }
             }

             if (gameObject.tag == "Player")//when cannonballs hit player
            {
                 //destroy cannonballs on impact
                 Destroy(coll.gameObject);
                 //play impact sound
                 splash.Play();
                 //subtract from health count in gameEngine script
                 GameObject.Find("GameEngine").GetComponent<gameEngine>().health--;
                 //check health and play sound if current changes
                if (hits == 1)
                {
                   health7.Play();
                }
                else if (hits == 2)
                {
                   health6.Play();
                }
                else if (hits == 3)
                {
                   health5.Play();
                }
                else if (hits == 4)
                {
                   health4.Play();
                }
                else if (hits == 5)
                {
                   health3.Play();
                }
                else if (hits == 6)
                {
                   health2.Play();
                }
                else if (hits == 7)
                {
                   health1.Play();
                }
                //keep track of hits to player
                hits++;
            }

             else //when cannonballs miss
             {
                  //destroy cannonball
                  Destroy(coll.gameObject);
                  //play impact sound
                  splash.Play();
             }
         }


     }
}
