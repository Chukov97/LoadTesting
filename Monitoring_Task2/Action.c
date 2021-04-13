Action()
{
	char arrayPrice[50], arrayCheck[50];
	int elemCnt, cost, x, randomize, countTick = 0;
	char *checkForChoose;
	char *check;
	int Tick =0;
	
	/* flights */
	//tName = "03.OpenPage_ticket_FindFlight";
	//lr_start_transaction(tName);
	
	web_reg_save_param_ex(
    "ParamName=TypeofSeat",
    "LB=seatType\" value=\"",
    "RB=\"",
    "Ordinal={Rand1}",
    SEARCH_FILTERS,
    LAST);
	
	web_reg_save_param_ex(
    "ParamName=TypeofPref",
    "LB=seatPref\" value=\"",
    "RB=\"",
    "Ordinal={Rand2}",
    SEARCH_FILTERS,
    LAST);
	

	web_url("Search Flights Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=search", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t13.inf", 
		"Mode=HTML", 
		LAST);
	//end_transaction(tName, status); //lr_think_time(3);
	
	//tName = "04.Create_ticket_FindFlight";
	//lr_start_transaction(tName);
	

	web_reg_save_param_ex(
    "ParamName=OFlight1", 
    "LB/IC=name=\"outboundFlight\" value=\"",
    "RB/IC=\"",
    "Ordinal=all",
	LAST);
	
	web_reg_save_param_ex(
    "ParamName=Price",
      "LB=$ ",
      "RB=<",
      "Ordinal=all", 
    LAST);

	web_submit_data("reservations.pl", 
		"Action=http://localhost:1080/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/reservations.pl?page=welcome", 
		"Snapshot=t14.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=depart", "Value={City1}", ENDITEM, 
		"Name=departDate", "Value={Data1}", ENDITEM, 
		"Name=arrive", "Value={City2}", ENDITEM, 
		"Name=returnDate", "Value={Data2}", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=seatPref", "Value=None", ENDITEM, 
		"Name=seatType", "Value=First", ENDITEM, 
		"Name=.cgifields", "Value=roundtrip", ENDITEM, 
		"Name=.cgifields", "Value=seatType", ENDITEM, 
		"Name=.cgifields", "Value=seatPref", ENDITEM, 
		"Name=findFlights.x", "Value=51", ENDITEM, 
		"Name=findFlights.y", "Value=11", ENDITEM, 
		LAST);
	
		//end_transaction(tName, status); //lr_think_time(3);

	/* cont */
	elemCnt = atoi(lr_eval_string("{Price_count}"));
	checkForChoose = lr_eval_string("{OFlight1_1}");
	
	   for(x=1;x<=elemCnt;x++){
          sprintf(arrayPrice, "{Price_%d}", x);
          cost =atoi(lr_eval_string(arrayPrice));
            if ((cost%2)==0) {
            Tick++;
            
            sprintf(arrayCheck, "{OFlight1_%d}", x); 
            check = lr_eval_string(arrayCheck);
            lr_output_message ("Цена билета %d:", cost);
              
          checkForChoose=check;
          lr_output_message("Параметры билета %s",checkForChoose);
         // srand(time(NULL));
  		  //randomize = rand() % Tick + 1;
          lr_output_message("Выбран рейс со стоимостью: %d", cost);
          lr_save_string(checkForChoose,"checked");
	         
              }
          
          else {
              countTick+=1;
              }   
 		        
  }
	
  lr_output_message("Количество билетов с чётной ценой %d",Tick); 
  lr_output_message("Количество билетов с нечетной стоимостью %d",countTick);
  
  if(countTick==4) {
   
    vuser_end();
    
  }
                 
	//tName = "05.Create_ticket_ChooseCost";
	//lr_start_transaction(tName);

	web_submit_data("reservations.pl_2", 
		"Action=http://localhost:1080/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/reservations.pl", 
		"Snapshot=t15.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=outboundFlight", "Value={checked}", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=seatType", "Value=First", ENDITEM, 
		"Name=seatPref", "Value=None", ENDITEM, 
		"Name=reserveFlights.x", "Value=73", ENDITEM, 
		"Name=reserveFlights.y", "Value=13", ENDITEM, 
		LAST);
	
	//end_transaction(tName, status); //lr_think_time(3);

	/* cont */
	//tName = "06.Create_ticket_PaymentDetail";
	//lr_start_transaction(tName);

	web_submit_data("reservations.pl_3", 
		"Action=http://localhost:1080/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/reservations.pl", 
		"Snapshot=t16.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=firstName", "Value={FirstName}", ENDITEM, 
		"Name=lastName", "Value={LastName}", ENDITEM, 
		"Name=address1", "Value={Addres}", ENDITEM, 
		"Name=address2", "Value={City}", ENDITEM, 
		"Name=pass1", "Value={FirstName} {LastName}", ENDITEM, 
		"Name=creditCard", "Value={Card}", ENDITEM, 
		"Name=expDate", "Value={ExpDate}", ENDITEM, 
		"Name=oldCCOption", "Value=", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=seatType", "Value={TypeofSeat}", ENDITEM, 
		"Name=seatPref", "Value={TypeofPref}", ENDITEM, 
		"Name=outboundFlight", "Value={checked}", ENDITEM, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=returnFlight", "Value=", ENDITEM, 
		"Name=JSFormSubmit", "Value=off", ENDITEM, 
		"Name=.cgifields", "Value=saveCC", ENDITEM, 
		"Name=buyFlights.x", "Value=69", ENDITEM, 
		"Name=buyFlights.y", "Value=2", ENDITEM, 
		LAST);
	
	//end_transaction(tName, status); //lr_think_time(3);

	/* itirerary */
	//lr_think_time(13);

	web_url("Itinerary Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=itinerary", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=flights", 
		"Snapshot=t17.inf", 
		"Mode=HTML", 
		LAST);
	
	//end_transaction(tName, status); //lr_think_time(3);
	
	return 0;
}
