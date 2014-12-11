//####default parameters

var default_startDay='2013-12-31'; //day when we start to display the poppin (format : YYYY-MM-DD)
var default_endDay='2014-01-31'; //day when we stop to display the poppin (format : YYYY-MM-DD)
var default_cookieDuration=6; //duration in hours for the cookie expiration


//extends jquery
(function(jQuery) {
    jQuery.fn.AWNewYearPoppin = function(params) {
		//extends parameters with default values
		params = jQuery.extend({startDay: default_startDay, endDay: default_endDay, cookieDuration:default_cookieDuration}, params);
		var oNewYearPoppin=new NewYearPoppin(params);
		oNewYearPoppin.modalShow();
		return this;
	}
})(jQuery);



function NewYearPoppin(params){
	
	//attributes
	this.params=params;
	this.cookieExiprationDate=null;
		
	//methods
	this.modalShow=function(){
		oNewYearPoppin=this;
		this._getExpireDate();
		var oDate=new Date();
		var today=oDate.getTime();
		var endDay=this._getTimeStampFromDateString(oNewYearPoppin.params.endDay).getTime();
		var startDay=this._getTimeStampFromDateString(oNewYearPoppin.params.startDay).getTime();
	
		
		//check if cookie is already set and if the poppin is in the date it should be displayed
		if ($.cookie('modal_shown') == null && today>startDay && today<endDay) {
			//set cookie in order to display the poppin only once a day
			$.cookie('modal_shown', 'yes', { expires: oNewYearPoppin.cookieExiprationDate, path: '/' });
			//show poppin
			$(".fancybox").fancybox({'showCloseButton':true});
			//manage hover event on button
			$(".carte-voeux-button").mouseover(function(){$(this).addClass('carte-voeux-button-hover');});
			$(".carte-voeux-button").mouseout(function(){$(this).removeClass('carte-voeux-button-hover');});
			
			$(".fancybox").eq(0).trigger('click');
		}
	}
		
	
	this._getTimeStampFromDateString=function(stringDate){
		var Year;
		var Month;
		var Day;
		
		Year=parseInt(stringDate.split("-")[0]);
		Month=parseInt(stringDate.split("-")[1])-1; //monthes start at 0 (January is 0...)
		Day=parseInt(stringDate.split("-")[2]);
		
		var date = new Date();
		
		date.setFullYear(Year);
		date.setMonth(Month);
		date.setDate(Day);
		
		
		return date;
	}
	
	this._getExpireDate=function(){
		oNewYearPoppin=this;
		var expire = new Date();
		var time = expire.getTime();
		time += oNewYearPoppin.params.cookieDuration*3600 * 1000;
		expire.setTime(time);
		oNewYearPoppin.cookieExiprationDate=expire;
	}
	
}