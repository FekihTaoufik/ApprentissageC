public class principal {
  public static void main(String[] args) {

    MoyennePOO m = new MoyennePOO();
    /*
    m.ajouteNote(15);
    m.ajouteNote(7);
    m.ajouteNote(12);
    m.ajouteNote(17);
    System.out.println(m.calculMoyenne());
    */
    //* 1- Comment faire pour tester cette classe ?
    // ! Moyenne m = new Moyenne(); dans la méthode principale 
    //* 2- Que se passe-t-il si on calcule la moyenne sans avoir saisi de notes ?
    // ! Résultat => NaN
    //* 3- Que se passe-t-il si on enlève le (double) ligne 11 ? Que se passe-t-il lors si on calcule la moyenne sans avoir saisi de notes ?
    // ! On aura que dalle (.0) après la virgule
    //* 4- Peut-on mettre la méthode main directement dans la classe Moyenne ou faut-il nécessairement créer une classe TestMoyenne ?
    // ! on ne peut pas mettre la méthode main directement dans la classe Moyenne, il faut nécessairemennt créer une classe TestMoyenne
    m.definirPresence(5);
    m.ajouteNote(10,1.5);
    System.out.println(m.calculNoteFinale());
    
    //* 5- Que faire si on décide de mettre 3 notes écrites au lieu de 2 ?
    //* 6- Que faire si on veut ajouter des coefficients ?
    //* 7- Que faire si on veut garder la meilleure des trois notes ?
    //* 8- Que faire si on veut considérer d'autres matières avec des règles diférentes ?

  }
}