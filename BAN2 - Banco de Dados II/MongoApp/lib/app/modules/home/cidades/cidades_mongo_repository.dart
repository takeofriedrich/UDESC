import 'package:app_mobile/app/app_controller.dart';
import 'package:app_mobile/app/modules/home/cidades/interfaces/aeroportos_repository_interface.dart';
import 'package:app_mobile/app/modules/home/cidades/interfaces/cidades_repository_interface.dart';
import 'package:app_mobile/app/modules/home/cidades/models/cidade.dart';
import 'package:flutter_modular/flutter_modular.dart';
import 'package:dio/native_imp.dart';
import 'package:mongo_dart/mongo_dart.dart';

part 'cidades_mongo_repository.g.dart';

@Injectable()
class CidadesMongoRepository extends ICidadesRepository {
  Db connection = Modular.get<AppController>().mongoConnection;

  //dispose will be called automatically
  @override
  void dispose() {}

  @override
  Future<Cidade> buscarCidade(int cod) async {
    Cidade cidade;
    List<Map<String, dynamic>> jsons =
        await connection.collection('cidades').find({'_id': cod}).toList();
    cidade = Cidade.fromMap(jsons.first);
    return cidade;
  }

  @override
  Future<List<Cidade>> buscarCidades() async {
    List<Cidade> cidades = [];
    List<Map<String, dynamic>> jsons =
        await connection.collection('cidades').find().toList();
    jsons.forEach((element) async {
      Cidade c = Cidade.fromMap(element);
      c.aeroportos =
          await Modular.get<IAeroportosRepository>().buscarAeroportos(c.codC);
      print(c.aeroportos);
      cidades.add(c);
    });
    return cidades;
  }
}
