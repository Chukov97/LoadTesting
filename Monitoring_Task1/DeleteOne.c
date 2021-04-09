DeleteOne()
{
	tName = "08_1.DeleteOne";
	lr_start_transaction(tName);	
		
	status=web_submit_data("itinerary.pl", 
		"Action=http://localhost:1080/cgi-bin/itinerary.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/itinerary.pl", 
		"Snapshot=t18.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=1", "Value=on", ENDITEM, 
		"Name=flightID", "Value={FlightID_1}", ENDITEM, 		
		"Name=.cgifields", "Value=1", ENDITEM, 
		"Name=removeFlights.x", "Value=51", ENDITEM, 
		"Name=removeFlights.y", "Value=9", ENDITEM, 
		LAST);

	end_transaction(tName, status); //lr_think_time(3);
	
	return 0;
}
