import 'package:app_mobile/app/app_controller.dart';
import 'package:app_mobile/app/modules/home/cidades/models/cidade.dart';
import 'package:app_mobile/app/modules/home/comprar/voos/interfaces/voos_repository_interface.dart';
import 'package:flutter/src/material/time.dart';
import 'package:app_mobile/app/modules/home/comprar/voos/models/voo.dart';
import 'package:flutter_modular/flutter_modular.dart';
import 'package:dio/native_imp.dart';
import 'package:mongo_dart/mongo_dart.dart';

part 'voos_mongo_repository.g.dart';

@Injectable()
class VoosMongoRepository extends IVoosRepository {
  Db connection = Modular.get<AppController>().mongoConnection;
  @override
  void dispose() {}

  @override
  Future<List<Voo>> listarVoos(Cidade origem, Cidade destino, DateTime data,
      TimeOfDay horarioSaida, TimeOfDay horarioChegada) async {
    DateTime saida = DateTime.utc(data.year, data.month, data.day,
        horarioSaida.hour, horarioSaida.minute);
    DateTime saidaMax = saida.add(Duration(hours: 3));
    DateTime chegada = DateTime.utc(data.year, data.month, data.day,
        horarioChegada.hour, horarioChegada.minute);
    DateTime chegadaMin = chegada.subtract(Duration(hours: 3));
    DateTime chegadaMax = chegada.add(Duration(hours: 3));
    print('saida: $saida - $saidaMax');
    print('chegada: $chegadaMin - $chegadaMax');
    print('origem: ${origem.codC}');
    print('destino: ${destino.codC}');
    var j = {
      'origem': origem.codC,
      'destino': destino.codC,
    };

    print(j);

    List<Voo> voos = [];

    // List<Map<String, dynamic>> jsons = await connection
    //     .collection('voos')
    //     .find(where
    //         .gte('data', saida)
    //         .and(where.lte('data', saidaMax))
    //         .and(where.gte('chegadaprevista', chegadaMin))
    //         .and(where.lte('chegadaprevista', chegadaMax))
    //         .and(where.eq('origem', '${origem.codC}'))
    //         .and(where.eq('destino', '${destino.codC}')))
    //     .toList();
    // jsons.forEach((element) {
    //   print(element);
    // });

    List<Map<String, dynamic>> jsons =
        await connection.collection('voos').find(j).toList();
    jsons.forEach((element) {
      print(element);
    });

    return voos;
  }

  @override
  Future<Voo> select(int codv) {
    // TODO: implement select
    throw UnimplementedError();
  }
}
