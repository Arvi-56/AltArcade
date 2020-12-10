using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class gameEngine : MonoBehaviour
{
     //current state of game finite state machine
     public string state;

     //health of player
     public int health;

     //number of enemies killed
     public int casualty;

     //keep tracks of frames the game is in "wait" mode
     //used for debugging coroutines
     public int timer;

     //keep tracks of frames the game is in "idle" mode
     //used to space out "press the button to begin" audio
     private int counter;

     //used to limit level launches to 1
     public bool toggle1;
     public bool toggle2;
     public bool toggle3;
     public bool toggle4;
     public bool dead;
     public bool redo;

     //audiosurces for game scripts
     public AudioSource begin;
     public AudioSource intro;
     public AudioSource winner;
     public AudioSource loser;
     public AudioSource level1;
     public AudioSource level2;
     public AudioSource level3;
     public AudioSource level4;
     public AudioSource level5;
     public AudioSource health8;


     //array of all possible enemy colliders
     public List<Collider> enemies = new List<Collider>();

     //array of enemies per lvl
     public List<Collider> lvl1 = new List<Collider>();
     public List<Collider> lvl2 = new List<Collider>();
     public List<Collider> lvl3 = new List<Collider>();
     public List<Collider> lvl4 = new List<Collider>();
     public List<Collider> lvl5 = new List<Collider>();

     void Start()
     {
          //set beginning game mode
          state = "idle";
          counter = 0;


          //play beginning audio clip
          begin.Play();

          //disable colliders for all enemies
          for (int i = 0; i < enemies.Count; i++)
          {
               var enemy =  enemies[i];
               var m_Collider = enemy.GetComponent<Collider>();
               m_Collider.enabled = false;
          }

          //randomly assign enemies of each lvl
          //lvl1
          lvl1.Add(enemies[Random.Range(0, enemies.Count)]);

          //lvl2
          for (int i = 0; i < 2; i++)
          {
               var rand = enemies[Random.Range(0, enemies.Count)];
               lvl2.Add(rand);
               enemies.Remove(rand);
          }
          for (int i = 0; i < lvl2.Count; i++)
          {
               enemies.Add(lvl2[i]);
          }

          //lvl3
          for (int i = 0; i < 3; i++)
          {
               var rand = enemies[Random.Range(0, enemies.Count)];
               lvl3.Add(rand);
               enemies.Remove(rand);
          }
          for (int i = 0; i < lvl3.Count; i++)
          {
               enemies.Add(lvl3[i]);
          }

          //lvl4
          for (int i = 0; i < 4; i++)
          {
               var rand = enemies[Random.Range(0, enemies.Count)];
               lvl4.Add(rand);
               enemies.Remove(rand);
          }
          for (int i = 0; i < lvl4.Count; i++)
          {
               enemies.Add(lvl4[i]);
          }

          //lvl5
          for (int i = 0; i < 5; i++)
          {
               var rand = enemies[Random.Range(0, enemies.Count)];
               lvl5.Add(rand);
               enemies.Remove(rand);
          }
          for (int i = 0; i < lvl5.Count; i++)
          {
               enemies.Add(lvl5[i]);
          }
     }

     void Update()
     {
          if (Input.GetKeyDown (KeyCode.R) && redo==true)
          {
               Debug.Log("restart");
               state = "idle";
          }

          if (Input.GetKeyDown (KeyCode.Y))
          {
               health = 0;
          }

          if (state=="idle")
          {
               Idle();
          }

          if (state=="intro")
          {
               Intro();
          }

          if (state=="lvl1")
          {
               StartCoroutine(Lvl1());

          }

          if (state=="lvl2")
          {
               StartCoroutine(Lvl2());
          }

          if (state=="lvl3")
          {
               StartCoroutine(Lvl3());
          }

          if (state=="lvl4")
          {
               StartCoroutine(Lvl4());
          }

          if (state=="lvl5")
          {
               StartCoroutine(Lvl5());
          }

          if (state=="wait") //switches levels if all enemies are killed
          {
               timer++;
               //Lvl 1 switcher
               if (casualty==1 && toggle1==true)
               {
                    Debug.Log("Lvl 1 Triumph!");
                    toggle1 = false;
                    state="lvl2";
               }
               //Lvl 2 switcher
               if (casualty==3 && toggle2==true)
               {
                    Debug.Log("Lvl 2 Triumph!");
                    toggle2 = false;
                    state="lvl3";
               }
               //Lvl 3 switcher
               if (casualty==6 && toggle3==true)
               {
                    Debug.Log("Lvl 3 Triumph!");
                    toggle3 = false;
                    state="lvl4";
               }
               //Lvl 4 switcher
               if (casualty==10 && toggle4==true)
               {
                    Debug.Log("Lvl 4 Triumph!");
                    toggle4 = false;
                    state="lvl5";
               }
               //Lvl 5 switcher
               if (casualty==15)
               {
                    Survive();
               }

               //Death Sequence
               if (health == 0 && dead==false)
               {
                   Death();
                   dead=true;
               }
          }
    }



    void Idle ()
    {
         Debug.Log("Launching Idle Mode");
         counter = counter+1;

         //set and reset values
         health = 8;
         casualty = 0;
         timer = 0;
         toggle1= true;
         toggle2= true;
         toggle3= true;
         toggle4= true;

         dead= false;
         redo = false;

         if (counter == 1000)
         {
              begin.Play();
              counter=0;
         }

         if (Input.GetKeyDown (KeyCode.Q))
         {
              state = "intro";
              intro.Play();
         }
    }

    void Intro()
    {
         Debug.Log("Launching Intro Mode");
         begin.Stop();

         if (Input.GetKeyDown (KeyCode.Space))
         {
              intro.Stop();
              state = "lvl1";
         }
    }

    void Survive()
    {
         winner.Play();
         Debug.Log("You Won");
         redo = true;
    }

    void Death()
    {
         loser.Play();
         Debug.Log("You Died");
         redo = true;
    }



    IEnumerator Lvl1()
    {
         Debug.Log("Launching Level 1");
         level1.Play();
         //enable collider of lvl enemies
         var enemy =  lvl1[0];
         var m_Collider = enemy.GetComponent<Collider>();
         m_Collider.enabled = true;
         //Debug.Log(lvl1[0]);
         state = "wait";
         yield return null;
    }

    IEnumerator Lvl2()
    {
         Debug.Log("Launching Level 2");
         level2.Play();
         //enable collider of lvl enemies
         for (int i = 0; i < lvl2.Count; i++)
         {
              var enemy =  lvl2[i];
              var m_Collider = enemy.GetComponent<Collider>();
              m_Collider.enabled = true;
              //Debug.Log(lvl2[i]);
         }
         state = "wait";
         yield return null;
    }

    IEnumerator Lvl3()
    {
         Debug.Log("Launching Level 3");
         level3.Play();
         //enable collider of lvl enemies
         for (int i = 0; i < lvl3.Count; i++)
         {
              var enemy =  lvl3[i];
              var m_Collider = enemy.GetComponent<Collider>();
              m_Collider.enabled = true;
              //Debug.Log(lvl3[i]);
         }

         state = "wait";
         yield return null;
    }

    IEnumerator Lvl4()
    {
         Debug.Log("Launching Level 4");
         level4.Play();
         //enable collider of lvl enemies
         for (int i = 0; i < lvl4.Count; i++)
         {
              var enemy =  lvl4[i];
              var m_Collider = enemy.GetComponent<Collider>();
              m_Collider.enabled = true;
              //Debug.Log(lvl4[i]);
         }

         state = "wait";
         yield return null;
    }

    IEnumerator Lvl5()
    {
         Debug.Log("Launching Level 5");
         level5.Play();
         //enable collider of lvl enemies
         for (int i = 0; i < lvl5.Count; i++)
         {
              var enemy =  lvl5[i];
              var m_Collider = enemy.GetComponent<Collider>();
              m_Collider.enabled = true;
              //Debug.Log(lvl5[i]);
         }

         state = "wait";
         yield return null;
    }

}
