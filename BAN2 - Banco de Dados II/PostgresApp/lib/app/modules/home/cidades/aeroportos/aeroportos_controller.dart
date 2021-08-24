import 'package:app_mobile/app/modules/home/cidades/models/cidade.dart';
import 'package:mobx/mobx.dart';
import 'package:flutter_modular/flutter_modular.dart';

part 'aeroportos_controller.g.dart';

@Injectable()
class AeroportosController = _AeroportosControllerBase
    with _$AeroportosController;

abstract class _AeroportosControllerBase with Store {
  @observable
  Cidade cidade;
}
