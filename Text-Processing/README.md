####Text Processor 
Just a really simple implementation of the *Decorator* software design pattern. 


**How to run:**
Enter the source-file of the text to be processed (or stdin), and add the processes you wish to cascade onto the text.
```
L337: Converts to leetspeak
Lower: Converts all characters to lower case
DoubleCon: Doubles all consonants
Caesar X: Advances each letter by X spaces (so replaced by the letter occuring X places down)
```

Example run:
```
stdin L337 Lower Caesar 5
```
