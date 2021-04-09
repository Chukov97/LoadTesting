DeleteAll()
{
	tName = "08_2.DeleteAll";
	lr_start_transaction(tName);
	
	status=web_submit_data("itinerary.pl_2", 
		"Action=http://localhost:1080/cgi-bin/itinerary.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/itinerary.pl", 
		"Snapshot=t19.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=flightID", "Value={FlightID_1}", ENDITEM, 			
		"Name=.cgifields", "Value=1", ENDITEM, 
		"Name=removeAllFlights.x", "Value=51", ENDITEM, 
		"Name=removeAllFlights.y", "Value=11", ENDITEM, 
		LAST);
	
	end_transaction(tName, status); //lr_think_time(3);

	return 0;
}
