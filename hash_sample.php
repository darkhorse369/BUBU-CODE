/*
if !hash redirects, if hash>128 redirects, if hash is empty redirects
hash is also sanitized only allowing a-z : 0-9.
Output only visible thru consoles for debuging puposes.
*/

<?php

function phash(){
if (!isset($_GET['hash'])) {header('Location:index.php');} 

else {
    $in = preg_replace("/[^a-zA-Z0-9]+/", "", $_GET['hash']);
    if ($in != "") {
        if (strlen($in) > 128) {
            header('Location:index.php');
            print "Length of variable needs to be < 128\n";
            return -1;
        }
        else{
    
        $encoded = hash("sha256", $in);
       echo $encoded;
    }}
    else{
        header('Location:index.php');
        print("hash variable cannot be empty!");}
}
}

phash();
?>
