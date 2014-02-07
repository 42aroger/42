<?php
//DataBase Config
date_default_timezone_set('Europe/Paris');

try
{
$bdd = new PDO('mysql:host=127.0.0.1;dbname=name', 'user', 'password');
$bdd->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_WARNING);
}
catch (Exception $e)
{
        die('Erreur : ' . $e->getMessage());
}

//Files Directory
$numberurl = 0; //Définir le nombre de baseurl (Attention, on par de 0; si vous en avez 3 vous devez écrire 2!)
$baseurl[0] = 'download/'; //Chemin du dossier de téléchargement | Ne pas oublier le / !!!
//$baseurl[1] = '';
//$baseurl[2] = '';
//$baseurl[3] = '';


//Config
$sitename = 'Site name'; //Nom du site web 
$siteurl = 'http://www.url.com/'; //URL du site web | Ne pas oublier le / à la fin !
$siteemail = 'admin@url.com'; //Addresse email d'envoie
$urldirectory = ''; //Directory URL ex: http://mysite/test => you setup like this  $urldirectory = 'test/';

//Register
$register = 1; // 1 => Inscription ouverte | 0 => Inscription fermé

//Log ip
$logip = 1; // 0 => Pas de log d'ip | 1 => Log des ips !

if (!class_exists('DateTime')) {
class DateTime {
public $date;

public function __construct($date) {
$this->date = strtotime($date);
}

public function setTimeZone($timezone) {
return;
}

private function __getDate() {
return date(DATE_ATOM, $this->date);
}

public function modify($multiplier) {
$this->date = strtotime($this->__getDate() . ' ' . $multiplier);
}

public function format($format) {
return date($format, $this->date);
}
}
}
?>
