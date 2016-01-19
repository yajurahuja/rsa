# RSA Implementation
There are 3 programs which are used to implement all the 3 parts of the algorithm as described [here](http://pajhome.org.uk/crypt/rsa/index.html)

### ALICE1.CPP
  * Inititally two prime numbers are chosen out randomly from a list of large prime numbers.
  * Then these numbers are used to generate the public and private keys.
  * The private key is displayed on the screen and has to be noted down
  * The public key is stored in a file

### BOB.CPP
  * Initially a message is asked as an input from the user.
  * This message is encrypted using the public key and stored in a file **message.txt**

### ALICE2.CPP
  * The program asks for the private key and uses it to decrypt the message stored in the file
