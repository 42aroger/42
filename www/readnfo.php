<?php 
//					//
//Author : @Seriesme//
//					//
error_reporting(E_ALL);
session_start();
include("includes/config.php");
include("includes/functions.php");

//Si déjà identifié 
if (isset($_SESSION['id']) && isset($_SESSION['username'])) {

	//Si file non spécifié
	if (empty($_GET['file']))
	{
		header ("Location: index.php");
	}
	
	else
	{
		$nfolink = isset($_GET['file']) ? htmlspecialchars($_GET['file']) : null;
		$basenfo = basename($nfolink);
		$arraynfo = explode(".",$basenfo);
		$total = count($arraynfo);
		$total--;
		
		//On vérifie si l'extension est bien nfo
		if ($arraynfo[$total] == "nfo")
		{
			header('Content-Type: text/plain; charset=ansi'); 
			$shownfo = file_get_contents(''.$nfolink.'');
			echo $shownfo;
		}
		//Sinon on le redirige (on va eviter de pouvoir lire des .php quand même 
		else
		{
		header ("Location: index.php");
		}
		
	}
}
//Sinon
else { header ("Location: login.php"); }

?>