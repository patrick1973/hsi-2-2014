int
BinarySearchStudentsFile (char* FileName, int Number, STUDENT* StudentPtr)
{
	int Result = -1;
	int totalElements =0;
	int first=0, last=0, middel;
	bool succes = false;

	// TODO: implement
	FILE *fp = NULL;
	fp = fopen(FileName, "rb" );
	if (fp !=NULL && StudentPtr != NULL)
	{
		fseek(fp,0,SEEK_END);								// zet de file pointer naar het einde van de file
		totalElements = ftell(fp)/sizeof(STUDENT);	// bepaal hoeveel elementen (studenten) er in de file staan.
		last = totalElements;	                    		// last bevat de positie van het laatste element. -1 omdat we beginen te tellen vanaf 0
		middel = (last - first) / 2;								// dus bij oneven getallen naar beneden. 7- 1 / 2 = 3
		rewind(fp);                                 				// filepointer terug naar het begin
		while(first <= last && succes == false)
		{
			fseek(fp, middel*sizeof(STUDENT),SEEK_SET); // zet de file pointer naar het middelste element.
			fread(StudentPtr,sizeof(STUDENT),1,fp); 		    // deze functie hoogt de file pointer 1 op na het lezen. daar om moet in onderstaande regel -1 staan.			
			//* for debug */  printf("actuele positie van de file pointer is %ld en daar staat studentnummer: %d nummer wat we zoeken is %d\n",(ftell(fp)/sizeof(STUDENT)-1),StudentPtr->StudentNumber, Number);
			/*for debug */ printf("first : %d  last: %d  midde : %d\n",first,last,middel);
			if ( Number < StudentPtr->StudentNumber)    		// als het gezochte nummer kleiner is dan het gevonde midde nummer
			{
				/*for debug */ printf("Te zoeken nummer dit in het linkerdeel \n");
				/*for debug */ printf("Te zoeken nummer is %d en het gevonden nummer is %d\n",Number,StudentPtr->StudentNumber);
				/* for debug*/ printf(" last = %d, first = %d het nieuwe midden is : %d\n",last,first,middel);
				last = middel -1;                       // het huidige midden is algecontroleerd dus last wordt 1 lager
				middel = (last - first) / 2;
				succes = false;
			}
			else if (Number > StudentPtr->StudentNumber )
			{
				/* for debug*/  printf("Te zoeken nummer dit in het rechter deel \n");
				/*for debug */ printf("Te zoeken nummer is %d en het gevonden nummer is %d\n",Number,StudentPtr->StudentNumber);
				/* for debug*/ printf(" last = %d, first = %d het nieuwe midden is : %d\n",last,first,middel);
				last = totalElements-1;
				first = middel +1;
				middel = ((last-first)/2)+(ftell(fp)/sizeof(STUDENT));
				
				succes = false;
			}
			else
			{
				//* for debug*/  printf("Gevonden\n");
				succes = true;
				Result = 0;
			}
			getchar();  // tijdelijk voor de test "press enter"
		}
	}
	else
	{
		Result = -1;
	}

	//*for debug */ printf("\n\nResultaat is : %d\n\n", Result);
	fclose(fp);
	return Result;
}
