import 'package:app_mobile/app/app_controller.dart';

import 'package:app_mobile/app/modules/home/cidades/aeroportos_postgres_repository.dart';
import 'package:app_mobile/app/modules/home/cidades/interfaces/cidades_repository_interface.dart';
import 'package:app_mobile/app/modules/home/cidades/models/cidade.dart';
import 'package:flutter_modular/flutter_modular.dart';
import 'package:postgres/postgres.dart';

part 'cidades_postgres_repository.g.dart';

@Injectable()
class CidadesPostgresRepository implements ICidadesRepository {
  PostgreSQLConnection connection = Modular.get<AppController>().connection;

  String sqlSelect = 'select * from buscarCidades()';
  String sqlSelect1 =
      'select codc as codc_, nome as nome_ from cidades where codc = @codc limit 1';

  @override
  Future<List<Cidade>> buscarCidades() async {
    List<Cidade> cidades = [];
    PostgreSQLResult resul = await connection.query(sqlSelect);
    resul.forEach((element) async {
      Map<String, dynamic> row = element.toColumnMap();
      Cidade c = Cidade.fromMap(row);
      c.aeroportos = await Modular.get<AeroportosPostgresRepository>()
          .buscarAeroportos(row['codc_']);
      cidades.add(c);
    });
    return cidades;
  }

  Future<Cidade> buscarCidade(int codc) {
    return connection
        .query(sqlSelect1, substitutionValues: {'codc': codc}).then((value) {
      return Cidade.fromMap(value.first.toColumnMap());
    });
  }

  //dispose will be called automatically
  @override
  void dispose() {}
}
