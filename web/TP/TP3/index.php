<?php 
date_default_timezone_set('Europe/Paris');
function kelvinToCelcius($kel){return $kel- 273.15;}
function generateBBString ($bb){
    return $bb[2].','.$bb[0].','.$bb[3].','.$bb[1];
}
function meteoArray($data){
    $arr=[];
    foreach ($data as $key => $d) {
        // echo '<pre>' , var_dump($key,(new DateTime())->format('Y-m-d'),$d,strpos($key,(new DateTime())->format('Y-m-d'))) , '</pre>';
        if(gettype(strpos($key,(new DateTime())->format('Y-m-d')))=='integer'){
            $arr=array_merge($arr,[$key=>$d]);
        }
    }
    return $arr;
}
if(isset($_POST['adresse'])){
    // Il te manque sa 
    ini_set('user_agent', 'PHP');

    $url ="http://nominatim.openstreetmap.org/search?q=".preg_replace("/ /", "%20",$_POST['adresse'])."&format=json";
    $jsonfile = file_get_contents($url);
    $data = json_decode(str_replace('\"','"',$jsonfile));
    if(count($data)>0){
        try{
            $url ="http://www.infoclimat.fr/public-api/gfs/json?_ll=".$data[0]->lat.",".$data[0]->lon."&_auth=AhhTRFQqBCZRfAcwD3kGL1Y%2BATRaLAIlC3dVNg5gUSwDZ1YyBGRcP1I%2BAH1Vegc0BShUNg43U20HZAtkWCoEeAJjUz5UPgRmUToHYQ8%2FBi1WegF8WmQCJQt3VToOYFEsA2FWMwRkXCBSPwBnVWEHLQU%2FVDQOLlN0B2ULaFg9BGcCaVMwVDIEZlE%2BB2UPIAYtVmABaVphAj4LbVVgDjVROgNpVjoEM1xsUjkAYVV7BzQFMVQzDjlTaQdjC25YNgR4An5TTlREBHtRfgcnD2oGdFZ4ATRaOwJu&_c=a4c69e2851123ac57a2cabb4a6ad2608";
            $jsonfile = file_get_contents($url);
            $meteo = json_decode(str_replace('\"','"',$jsonfile));
        }
        catch(Exception $ex){
            echo $ex;
        }
    }
}

?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>Accueil</title>
    <link href="https://fonts.googleapis.com/css?family=Open+Sans:300,400,600,700" rel="stylesheet">
    <link rel="stylesheet" href="./style.css">
</head>
<body>
    <div>
    <form action="index.php" method="POST" style="text-align:center;    margin-bottom: 50px;">
        <h3 style="font-weight: 100; font-size: 23px;">Veuillez saisir une adresse</h3>
        <textarea style="width: 450px; height: 65px; border: 1px solid lightgray; padding: 7px 10px; border-radius: 5px; box-shadow: 1px 2px 7px rgba(0,0,0,.2);" placeholder="Veuillez saisir une adresse..." name="adresse" cols="30" rows="10"><?php echo isset($_POST['adresse'])?$_POST['adresse']:'' ?></textarea>
        <br>
        <button style="margin-top: 10px;cursor: pointer; border-radius: 5px; border: 1px solid #97ddff; background-color: #46c3ff; color: white; padding: 5px 16px; font-size: 18px;" type="submit">Envoyer</button>
        </form>
    <?php
    if(isset($data)){
        ?>
            <hr style="width: 75%; margin-top: 40px; margin-bottom: 25px; border: 1px solid whitesmoke;">
            <?php if(count($data)<=0){ ?>
    <h3 style="font-weight: 100; font-size: 23px;text-align:center;">Nous n'avons trouvé aucun résultat, veuillez réessayer...</h3>
            <?php }else {?>
    <h3 style="font-weight: 100; font-size: 23px;text-align:center;">Nous avons trouvé <?= count($data) ?> résultats pour l'adresse "<?= $_POST['adresse'] ?>"</h3>
            <?php }?>
        <?php
        foreach ($data as $key => $d) {
            ?>
    <div style="width: 100%; height: 370px; text-align: center; margin-bottom: 30px;" >
        <iframe frameborder="0" style="    width: 45%; height: 100%; border: none; box-shadow: 1px 1px 3px black; display: inline-block;" src="http://www.openstreetmap.org/export/embed.html?bbox=<?php echo str_replace(',','%2C',generateBBString($data[0]->boundingbox)).'&amp;' ?>layer=mapnik"> </iframe>
    
            <div style="display: inline-block; width: 45%; height: 100%; margin-left: 20Px;">
                <table>
                <caption><img src="./weather.svg" alt="Weather" style="height:70px;"><br> Météo du jour : <?= (new DateTime())->format('d-m-Y H:i') ?> <br> <?php echo 'Latitude : '.$d->lat.' Longitude : '.$d->lon ?></caption>
                    <thead>
                        <tr>
                            <td>Heure</td>
                            <td>Température</td>
                            <td>Risque de pluie</td>
                            <td>Risque de neige</td>
                            <td>Humidité</td>
                            <td>Vitesse du vent</td>
                        </tr>
                    </thead>
                    <tbody>
                        <?php 
                        foreach (meteoArray($meteo) as $key => $m) {
                        ?>
                        <tr>
                            <td><?= (new DateTime($key))->format("H\h") ?></td>
                            <td><?= round(kelvinToCelcius($m->temperature->sol)) ?>°</td>
                            <td><?= $m->pluie ?> mm</td>
                            <td><?= $m->risque_neige ?></td>
                            <td><?= ((array)$m->humidite)["2m"] ?>%</td>
                            <td><?= ((array)$m->vent_moyen)["10m"] ?> km/h</td>
                        </tr>
                        <?php 
        }
                        ?>
                    </tbody>
                </table>
            </div>

    </div>
            <?php
        }
    }
    ?>
    </div>
</body>
</html>