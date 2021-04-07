Action()
{
	char arrayCity[50], arrayBox[50];
	int elemCnt, cost, x, min, check, Delete;
	char*cityN, *DeleteCity;
	char*London="London";
	

		web_reg_save_param_ex(
    "ParamName=Session", 
    "LB/IC=\"userSession\" value=\"",
    "RB/IC=\"/>",
    "Ordinal=1",
	LAST);

	web_url("webtours", 
		"URL=http://localhost:1080/webtours", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		LAST);

	/* login */

	//lr_think_time(16);

	web_submit_data("login.pl", 
		"Action=http://localhost:1080/cgi-bin/login.pl", 
		"Method=POST", 
		"TargetFrame=body", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?in=home", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=userSession", "Value={Session}", ENDITEM, 
		"Name=username", "Value=jojo", ENDITEM, 
		"Name=password", "Value=bean", ENDITEM, 
		"Name=JSFormSubmit", "Value=off", ENDITEM, 
		"Name=login.x", "Value=47", ENDITEM, 
		"Name=login.y", "Value=4", ENDITEM, 
		LAST);

	/* ininerary */

	//lr_think_time(16);
	
	web_reg_save_param_ex(
    "ParamName=FlightID", 
    "LB/IC=\"flightID\" value=\"",
    "RB/IC=\"",
    "Ordinal=all",
	LAST);
	
	web_reg_save_param_ex(
    "ParamName=Box", 
    "LB/IC=\"checkbox\" name=\"",
    "RB/IC=\"",
    "Ordinal=all",
	LAST);
	
	web_reg_save_param_ex(
    "ParamName=City",
      "LB=leaves ",
      "RB=  for",
      "Ordinal=all", 
    LAST);
	
	
	web_url("Itinerary Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=itinerary", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		LAST);
	
elemCnt = atoi(lr_eval_string("{City_count}"));	
lr_output_message("Number of tickets = %d",elemCnt);
Delete = atoi(lr_eval_string("{Box_1}"));

for(x=1;x<=elemCnt;x++){
          sprintf(arrayCity, "{City_%d}", x);
          cityN = lr_eval_string(arrayCity);
          sprintf(arrayBox, "{Box_%d}", x); 
          check = atoi(lr_eval_string(arrayBox));
      
          if (strcmp(cityN,London)!=0) {
            DeleteCity=cityN;
        Delete=check;
      lr_output_message ("Delete city is %s",DeleteCity);
    }
  }
  
  lr_save_int(Delete,"checkbox");

	/* chek */

	/* delete */

	//lr_think_time(22);
	
	web_submit_data("itinerary.pl", 
		"Action=http://localhost:1080/cgi-bin/itinerary.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/itinerary.pl", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name={checkbox}", "Value=on", ENDITEM, 
		"Name=flightID", "Value={FlightID_1}", ENDITEM, 
		"Name=flightID", "Value={FlightID_2}", ENDITEM, 
		"Name=flightID", "Value={FlightID_3}", ENDITEM, 
		"Name=.cgifields", "Value=1", ENDITEM, 
		"Name=.cgifields", "Value=3", ENDITEM, 
		"Name=.cgifields", "Value=2", ENDITEM, 
		"Name=removeFlights.x", "Value=54", ENDITEM, 
		"Name=removeFlights.y", "Value=10", ENDITEM, 
		LAST);
	return 0;
}
