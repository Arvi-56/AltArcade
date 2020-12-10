using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class DialMove : MonoBehaviour
{

     public GameObject projectile;
     public GameObject ship;
     public GameObject crash;
     public AudioSource cannon;
     public AudioSource creak1;
     public AudioSource creak2;


     void Start()
     {

     }

      void Update()
      {
           //These pivot player by set positions on keystroke
           if (Input.GetKeyDown (KeyCode.A))
           {
                ship.transform.rotation = Quaternion.Euler(-20, 270, 0);
           }
           if (Input.GetKeyDown (KeyCode.S))
           {
                ship.transform.rotation = Quaternion.Euler(-20, 290, 0);
           }

           if (Input.GetKeyDown (KeyCode.D))
           {
                ship.transform.rotation = Quaternion.Euler(-20, 315, 0);
                creak1.Play();
           }

           if (Input.GetKeyDown (KeyCode.F))
           {
                ship.transform.rotation = Quaternion.Euler(-20, 340, 0);
           }

           if (Input.GetKeyDown (KeyCode.G))
           {
                ship.transform.rotation = Quaternion.Euler(-20, 0, 0);
           }

           if (Input.GetKeyDown (KeyCode.H))
           {
                ship.transform.rotation = Quaternion.Euler(-20, 20, 0);
           }

           if (Input.GetKeyDown (KeyCode.J))
           {
                ship.transform.rotation = Quaternion.Euler(-20, 45, 0);
                creak2.Play();
           }

           if (Input.GetKeyDown (KeyCode.K))
           {
                ship.transform.rotation = Quaternion.Euler(-20, 70, 0);
           }

           if (Input.GetKeyDown (KeyCode.L))
           {
                ship.transform.rotation = Quaternion.Euler(-20, 90, 0);
           }

           if (Input.GetKeyDown (KeyCode.Z))
           {
                ship.transform.rotation = Quaternion.Euler(-20, 180, 0);
           }

           //launch cannon
           if (Input.GetKeyDown (KeyCode.Space))
           {
                //cannon sound
                cannon.Play();
                //positions crashing sound
                crash.transform.position = transform.position + transform.forward*20;
                crash.transform.position = new Vector3(crash.transform.position.x, 1, crash.transform.position.z);
                //creates and positions cannon ball
                GameObject cannonball = Instantiate (projectile);
                cannonball.transform.position = transform.position + transform.forward*2;
                //Launches cannon ball
                Rigidbody rb = cannonball.GetComponent<Rigidbody>();
                rb.velocity = transform.forward*15;
           }

      }
}
