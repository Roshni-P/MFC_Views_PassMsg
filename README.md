# MFC_Views_PassMsg
This example shows how to pass messages between different Views using MFC.

I have created a solution with two views - OddView & EvenView.
This is a simple example to show how Views can communicate with each other using PostMessage().
Each View has a button. On clicking the button on one view, the corresponding Odd/Even number gets incremented in the other view.
The flow of control is as below:
View->Mainframe->Display in the other view AND vice-versa.

As shown in figure below, ensure that both views are open initially to see the number updation.
<img width="623" alt="image" src="https://github.com/user-attachments/assets/dd41f507-04aa-4a96-8a29-f9a602cfe491">
