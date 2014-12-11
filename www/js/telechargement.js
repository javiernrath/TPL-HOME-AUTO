/**
 * Traite une demande de téléchargement de WampServer
 * Déclenche un événement Google Analytics et redirige vers le lien de téléchargement
 * 
 */
function telecharger() {
	// lancement événement Google Analytics
	// TODO VALEURS A MODIFIER SELON LA CONFIGURATION GOOGLE ANALYTICS
	_gaq.push(['_trackEvent', 'download', 'form', 'lead', 1]);

	// redirection vers le téléchargement après une petite pause pour laisser le temps à l'appel asynchrone à Google Analytics de passer
	var url=$('#fancybox-wrap a.lienLogiciel').attr('href');
	setTimeout("window.location.href='"+url+"'", 500);
}
