import 'package:app_mobile/app/app_controller.dart';
import 'package:app_mobile/app/modules/home/cidades/interfaces/aeroportos_repository_interface.dart';
import 'package:app_mobile/app/modules/home/cidades/interfaces/cidades_repository_interface.dart';
import 'package:app_mobile/app/modules/home/cidades/models/aeroporto.dart';
import 'package:flutter_modular/flutter_modular.dart';
import 'package:dio/native_imp.dart';
import 'package:mongo_dart/mongo_dart.dart';

part 'aeroportos_mongo_repository.g.dart';

@Injectable()
class AeroportosMongoRepository extends IAeroportosRepository {
  Db connection = Modular.get<AppController>().mongoConnection;

  //dispose will be called automatically
  @override
  void dispose() {}

  @override
  Future<Aeroporto> buscarAeroporto(int codA) async {
    Aeroporto aeroporto;
    List<Map<String, dynamic>> jsons =
        await connection.collection('aeroportos').find({'_id': codA}).toList();
    aeroporto = Aeroporto.fromMap(jsons.first);
    aeroporto.cidade = await Modular.get<ICidadesRepository>()
        .buscarCidade(int.parse(jsons.first['codc']));
    print(jsons);
    return aeroporto;
  }

  @override
  Future<List<Aeroporto>> buscarAeroportos(int codC) async {
    List<Aeroporto> aeroportos = [];
    List<Map<String, dynamic>> jsons = await connection
        .collection('aeroportos')
        .find({'codc': "$codC"}).toList();
    jsons.forEach((element) {
      aeroportos.add(Aeroporto.fromMap(element));
    });
    return aeroportos;
  }
}
