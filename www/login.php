﻿<?php
//					//
//Author : @Seriesme//
//					//
session_start();
include("includes/config.php");
include("includes/functions.php");


//Si déjà identifié on redirige
if (!empty($_SESSION['id']) AND !empty($_SESSION['username'])) {
header ("Location: index.php"); }

//Sinon si le formulaire est remplis (username)
else if (!empty($_POST['submit'])) {

// check if $_SESSION['qaptcha_key'] created with AJAX exists
if(isset($_SESSION['qaptcha_key']) && !empty($_SESSION['qaptcha_key']))
{
  $myVar = $_SESSION['qaptcha_key'];
 
  // check if the random input created exists and is empty
  if(isset($_POST[''.$myVar.'']) && empty($_POST[''.$myVar.'']))
  {
    //Captcha OK
	
		//On définie les variables
		$username = isset($_POST['username']) ? $_POST['username'] : null;
		$password = isset($_POST['password']) ? $_POST['password'] : null;

		//Hachage du mot de passe
		$pass_hache = sha1($_POST['password']);
		 
		//Vérification des identifiants
		$req = $bdd->prepare('SELECT id, rank FROM users WHERE username = :username AND password = :password');
		$req->execute(array(
		'username' => $username,
		'password' => $pass_hache));
		 
		$resultat = $req->fetch();
		 
		//Si les identifiants sont différents
		if (!$resultat)
		{
		header ("Refresh: 3;URL=login.php");
		echo '<!DOCTYPE html>
		<html lang="en">
		  <head>
			<meta charset="utf-8">
			<meta name="viewport" content="width=device-width, initial-scale=1.0">
			<meta name="description" content="">
			<meta name="author" content="">
			<link rel="shortcut icon" href="../../assets/ico/favicon.png">
			<script src="//ajax.googleapis.com/ajax/libs/jquery/1.9.1/jquery.min.js"></script>
			<title>Sign in</title>
			<link href="css/signin.css" rel="stylesheet">
			<link href="css/signin2.css" rel="stylesheet">
		 </head>

		  <body>

			<div class="container">
			<div class="alert alert-dismissable alert-danger">
					  <button type="button" class="close" data-dismiss="alert">&times;</button>
					  <strong>Sorry!</strong> <u>Incorrect</u> username or password.
					</div>';

		}
		//Si c'est bon
		else
		{
		echo'<!DOCTYPE html>
		<html lang="en">
		  <head>
			<meta charset="utf-8">
			<meta name="viewport" content="width=device-width, initial-scale=1.0">
			<meta name="description" content="">
			<meta name="author" content="">
			<link rel="shortcut icon" href="../../assets/ico/favicon.png">
			<script src="//ajax.googleapis.com/ajax/libs/jquery/1.9.1/jquery.min.js"></script>
			<title>Sign in</title>
			<link href="css/signin.css" rel="stylesheet">
			<link href="css/signin2.css" rel="stylesheet">
		 </head>

		  <body>

			<div class="container">';
			
		//On vérifie que le compte est bien activé
		$sqlact = $bdd->prepare('SELECT actived FROM users WHERE username = :username');
		$sqlact->execute(array('username' => $username)) or die;

		$activedornot = $sqlact->fetch();

		//Si le compte est bien activé on l'identifie
		if($activedornot['actived']==1) {

		if($logip==1) { $ip = get_ip (); }
		else { $ip ='0.0.0.0'; }
		$action = 'Log in';
		$date=date("Y-m-d");
		$time=date("H:i:s");
		$log = $bdd->prepare('INSERT INTO logs(uid, username, ip, action, date, time) VALUES(:uid, :username, :ip, :action, :date, :time)');
		$log->execute(array('uid' => $resultat['id'], 'username' => $username, 'ip' => $ip, 'action' => $action, 'date' => $date, 'time' => $time));
		//On redirige
		header ("Refresh: 3;URL=index.php");
		$_SESSION['id'] = $resultat['id'];
		$_SESSION['rank'] = $resultat['rank'];
		$_SESSION['username'] = $username;
		echo '<div class="alert alert-dismissable alert-info">
					  <button type="button" class="close" data-dismiss="alert">&times;</button>
					  <strong>Successfull sign in!</strong> You will be redirect soon.
					</div>
				<div class="progress progress-striped active">
						<div class="progress-bar progress-bar-success" style="width: 100%"></div>
					  </div>';
		}	

		//Sinon on l'informe
		elseif($activedornot['actived']==0) {

		echo '<div class="alert alert-dismissable alert-warning">
					  <button type="button" class="close" data-dismiss="alert">&times;</button>
					  <strong>Please activate your account!</strong> You can generate a new activation link <a href="register-activation.php?action=newvalidation" class="alert-link">here</a>.
					</div>';
		}	

											}
		  }
	
  else
  {
		echo '<!DOCTYPE html>
				<html lang="en">
				  <head>
					<meta charset="utf-8">
					<meta name="viewport" content="width=device-width, initial-scale=1.0">
					<meta name="description" content="">
					<meta name="author" content="">
					<link rel="shortcut icon" href="../../assets/ico/favicon.png">
					<script src="//ajax.googleapis.com/ajax/libs/jquery/1.9.1/jquery.min.js"></script>
					<title>Sign in</title>
					<link href="css/signin.css" rel="stylesheet">
					<link href="css/signin2.css" rel="stylesheet">
					<link rel="stylesheet" type="text/css" href="QapTcha.jquery.css" media="screen" />
					<script type="text/javascript" src="jquery.js"></script>
					<script type="text/javascript" src="jquery-ui.js"></script>
					<script type="text/javascript" src="jquery.ui.touch.js"></script>
					<script type="text/javascript" src="QapTcha.jquery.js"></script>
					<script type="text/javascript">
				  $(document).ready(function(){
					$(\'.QapTcha\').QapTcha({
					  autoSubmit : true,
					  autoRevert : true,
					  disabledSubmit : false,
					  PHPfile : \'Qaptcha.jquery.php\'
					});
				  });
				</script>
				 </head>

				  <body>

					<div class="container">

					  <form method="post" action="login.php" class="form-signin">
						<input type="text" name="username" class="form-control" placeholder="Username" autofocus>
						<input type="password" name="password" class="form-control" placeholder="Password">
						<div class="QapTcha"></div>
						<input type="submit" class="btn btn-lg btn-primary btn-block" name="submit" value="Sign in" />
					  </form>';
  }
}
unset($_SESSION['qaptcha_key']);


echo '</div> <!-- /container -->

  </body>
</html>
';
}

else
{
		echo '<!DOCTYPE html>
				<html lang="en">
				  <head>
					<meta charset="utf-8">
					<meta name="viewport" content="width=device-width, initial-scale=1.0">
					<meta name="description" content="">
					<meta name="author" content="">
					<link rel="shortcut icon" href="../../assets/ico/favicon.png">
					<script src="//ajax.googleapis.com/ajax/libs/jquery/1.9.1/jquery.min.js"></script>
					<title>Sign in</title>
					<link href="css/signin.css" rel="stylesheet">
					<link href="css/signin2.css" rel="stylesheet">
					<link rel="stylesheet" type="text/css" href="QapTcha.jquery.css" media="screen" />
					<script type="text/javascript" src="jquery.js"></script>
					<script type="text/javascript" src="jquery-ui.js"></script>
					<script type="text/javascript" src="jquery.ui.touch.js"></script>
					<script type="text/javascript" src="QapTcha.jquery.js"></script>
					<script type="text/javascript">
				  $(document).ready(function(){
					$(\'.QapTcha\').QapTcha({
					  autoSubmit : true,
					  autoRevert : true,
					  PHPfile : \'Qaptcha.jquery.php\'
					});
				  });
				</script>
				 </head>

				  <body>

					<div class="container">

					  <form method="post" action="login.php" class="form-signin">
						<input type="text" name="username" class="form-control" placeholder="Username" autofocus>
						<input type="password" name="password" class="form-control" placeholder="Password">
						<div class="QapTcha"></div>
						<input type="submit" class="btn btn-lg btn-primary btn-block" name="submit" value="Sign in" />
					  </form>';

}
?>
