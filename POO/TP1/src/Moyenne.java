class Moyenne {  
  int notes = 0 ;  
  int nombreDeNotes = 0 ;  
  void ajouteNote (int note) {  
    notes += note;  
    nombreDeNotes += 1;  
  }  
  double calculMoyenne() {  
    return ((double)notes) / nombreDeNotes ;  
  }  
}  