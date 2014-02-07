<?php
include("includes/config.php");
$sqlid=$bdd->prepare('SELECT lastid FROM config');
$sqlid->execute();
$sqllastid = $sqlid->fetch();
$lastid=$sqllastid['lastid'];

if(empty($lastid)) { header('Location: index.php'); }
else {
$delete1=$bdd->prepare('UPDATE config SET lastid = NULL');
$delete1->execute();
$chemin=''.$_SERVER['DOCUMENT_ROOT'].''.$urldirectory.'';
exec('cd '.$chemin.''); 
exec('/usr/local/bin/php run.php > /dev/null&');
header ("Refresh: 0.25; index.php");
}
?>
