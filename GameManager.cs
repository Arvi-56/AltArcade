using System.Collections;
using System.Collections.Generic;
using TMPro;
using UnityEngine;

public class GameManager : MonoBehaviour
{
     [Header("Ball")]
     public GameObject Ball;

     [Header("Player 1")]
     public GameObject Player1;
     public GameObject Player1Goal;

     [Header("Player 2")]
     public GameObject Player2;
     public GameObject Player2Goal;

     [Header("Score UI")]
     public GameObject Player1Score;
     public GameObject Player2Score;

     private int Player1Text;
     private int Player2Text;

     public void Player1Scored()
     {
          Player1Text++;
          Player1Score.GetComponent<TextMeshProUGUI>().text = Player1Text.ToString();
          ResetPosition();
     }
     public void Player2Scored()
     {
          Player2Text++;
          Player2Score.GetComponent<TextMeshProUGUI>().text = Player2Text.ToString();
          ResetPosition();
     }
     private void ResetPosition()
     {
          Ball.GetComponent<Ball>().Reset();
          Player1.GetComponent<Paddle>().Reset();
          Player2.GetComponent<Paddle>().Reset();
     }
}
